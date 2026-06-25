# Homework 10. Roads
## Requirements
A few weeks after "accepting the resignation letter from an" A.I. ethics 
researcher (Links to an external site.), a large tech company's A.I. went
rogue and decided to "disrupt the transportation industry" by making it's
self-driving cars destroy all the roads around Mountain View. Luckily, no people or infrastructure was harmed thanks to the Mitchells (Links to an external site.) who stopped the A.I.

Your job is to write a program reads in data about what roads/edges used to exist (what roads we can rebuild) and then outputs which road segments (edges, not entire roads/paths) we should rebuild first. There are two requirements:

- If we could get from node A to node B before the A.I. destroyed the roads, we should be able to get from node A to node B after rebuilding the roads.
- We want to rebuild the least amount of road (the least total length) possible because roads are expensive... or something.
You may discuss the homework as much as you like (in Canvas or Discord) as long as you don't share code for your solution.

## Data Format
There are two files that contain the data: nodes.txt (for nodes) and roads.txt (for edges).

This data is a simplified version of some data from openstreetmap.org (Links to an external site.). We're going to treat the data as if it represents an undirected graph (even though some roads are actually 1-way roads).

### nodes.txt
The first line of nodes.txt contains 4 doubles: minimum x coordinate, min y coordinate, maximum x coordinate, and max y coordinate

Every other line represents a 2D point (the nodes) which have 3 parts: a int_least64_t OSM ID that uniquely identifies that node, a double x coordinate, and a double y coordinate.

All coordinates are in kilometers.

Here's an example:
```
-8.280193126928674 -5.628216599999846 8.268958471249428 5.628216599999846
26027650 -3.1377879410553775 2.563702419600297
26027651 -2.6985453920733153 3.5639327087998054
26027653 -3.2265598654362253 2.441053738800085
26027655 -3.3576316196990637 2.3328570797998402
...
```
`roads.txt`
Every line in roads.txt has 3 main parts:

- A `int_least64_t` OSM ID that uniquely identifies that part of a road
- A list of Node IDs
  - The number of nodes, N, that make up that part of the road (in order)
  - N OSM IDs that for the nodes

- The name of the road

Note that the same road may show up multiple times because it has multiple parts.

The list of node IDs corresponds to multiple edges, for example the line `173846420 4 257878162 6093953294 6093463504 257877916 Foothill Expressway` denotes a part of a road `Foothill Expressway` with the unique ID `173846420` and `N = 4` nodes which represent the following N - 1 = 3 edges: (257878162, 6093953294), (6093953294, 6093463504), and (6093463504, 257877916).

Note: The graph is undirected, so in essence, the edges edges: (6093953294, 257878162), (6093463504, 6093953294), and (257877916, 6093463504) are also added.

```
...
172246147 2 1831703524 1831703525 South Fair Oaks Avenue
172246148 2 65515006 1831703524 South Fair Oaks Avenue
173846420 4 257878162 6093953294 6093463504 257877916 Foothill Expressway
173846425 16 257878172 6439285157 2497999653 272297873 272297872 430586728 1247892271 272297870 272297869 272297868 272297867 272297866 272297865 272297864 272297862 65400152 Foothill Expressway
174890533 17 65653802 6518635038 65457620 6518635037 2323163806 6473961499 65608871 6473961498 2323163808 7301457508 7301457504 7301457500 6473963471 65641377 6473963473 7824956488 65653798 Emerson Street
...
```
**Warning:** This data is... messy and hard to interpret in real life: A single "road" may be represented twice (once for each direction) xor just one time. There may be multiple different roads with the same name that are actually unrelated. To keep this data small, many unnamed roads and paths are missing. Some roads may not actually be usable by cars. Some roads are public while others are privately owned. -- You don't have to worry about this for the purpose assignment but you should know in case you ever want to use this kind of data for a real project.

### Example Program
Here's an example program that shows how you can read and interpret the data. You don't need to use any of this code; it's just here in case you find it helpful:

road_length_demo.cpp (Links to an external site.)
```cpp
#include <cmath>
#include <cstdint>
#include <exception>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::map;
using std::sqrt;
using std::string;
using std::vector;

class MyException : public exception {
  const char* msg;
public:
  MyException(const char* msg) : msg(msg) {}
  
  const char* what() const noexcept {
    return msg;
  }
};

typedef int_least64_t OSMID;

struct Node {
    double x, y;
};

struct Road {
    string name;
    vector<OSMID> path;
};

map<OSMID, Node> load_nodes(const string& file_name) {
  ifstream nodes_file(file_name);
  map<OSMID, Node> nodes;
  double min_x, min_y, max_x, max_y;
  if (nodes_file.bad() || nodes_file.fail()) {
    throw MyException("Error opening nodes file.");
  }
  nodes_file >> min_x >> min_y >> max_x >> max_y;
  while (nodes_file.good()) {
    OSMID osmid;
    double x, y;
    nodes_file >> osmid >> x >> y;
    if (nodes_file.good()) {
        nodes[osmid] = {x, y};
    }
  }
  if (nodes_file.bad()) {
    throw MyException("Error reading nodes from file.");
  }
  nodes_file.close();
  return nodes;
}

map<OSMID, Road> load_roads(const string& file_name) {
  map<OSMID, Road> roads;
  ifstream roads_file(file_name);
  long num_roads = 0;
  if (roads_file.bad() || roads_file.fail()) {
    throw MyException("Error opening roads file.");
  }
  while (roads_file.good()) {
    OSMID osmid;
    int path_len;
    roads_file >> osmid >> path_len;
    if (roads_file.good()) {
        Road r;
        r.path.reserve(path_len);
        for (int j = 0; j < path_len; ++j) {
          OSMID node_id;
          roads_file >> node_id;
          ++num_roads;
          r.path.push_back(node_id);
        }
      roads_file.get(); // Read the extra space
      getline(roads_file, r.name);
      roads[osmid] = r;
    }
  }
  if (roads_file.bad()) {
    throw MyException("Error reading roads from file.");
  }
  roads_file.close();
  return roads;
}

double distance(const Node& a, const Node& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_road_length(const map<OSMID, Node>& nodes, const Road& road) {
  double len = 0.0;
  for (size_t i = 1; i < road.path.size(); ++i) {
    const Node& a = nodes.find(road.path[i - 1])->second;
    const Node& b = nodes.find(road.path[i])->second;
    len += distance(a, b);
  }
  return len;
}

map<string, double> get_road_lengths( const map<OSMID, Node>& nodes,
                                      const map<OSMID, Road>& roads) {
  map<string, double> road_lengths;
  for (const auto& osmid_road : roads) {
    const Road& road = osmid_road.second;
    road_lengths[road.name] += get_road_length(nodes, road);
  }
  return road_lengths;
}

int main(int argc, char *argv[]) {
  const double min_road_len = 5.0; // km
  map<OSMID, Node> nodes = load_nodes(argc > 1 ? argv[1] : "nodes.txt");
  map<OSMID, Road> roads = load_roads(argc > 2 ? argv[2] : "roads.txt");
  map<string, double> road_lengths = get_road_lengths(nodes, roads);
  
  cout << "Roads that are at least " << min_road_len << "km:\n";
  for(const auto& name_length : road_lengths) {
    if (name_length.second > min_road_len) {
        cout << "  " << name_length.first << ": " << name_length.second << "km\n";
    }
  }
  cout << endl;
  return 0;
}
```
```shell
$ clang++ -pedantic -Wall -lm -std=c++20 -o road_length_demo hw09/road_length_demo.cpp
$ ./road_length_demo hw09/nodes.txt hw09/roads.txt
```

```
Roads that are at least 5km:
Adobe Wells: 6.31737km
Alma Street: 5.67885km
Alviso Slough Trail: 6.92572km
Arastradero Road: 7.39641km
Bayshore Freeway: 28.2508km
California Street: 5.08014km
Central Expressway: 24.9651km
East El Camino Real: 9.72684km
East Evelyn Avenue: 5.9932km
El Camino Real: 5.6116km
Foothill Expressway: 23.0364km
Fremont Avenue: 7.25051km
Grant Road: 7.32667km
Junipero Serra Freeway: 22.8402km
Lawrence Expressway: 16.941km
Miramonte Avenue: 5.15222km
North Fair Oaks Avenue: 5.40011km
North Mathilda Avenue: 8.77146km
North Shoreline Boulevard: 9.88598km
Page Mill Road: 11.4679km
Reservoir Road: 5.21237km
San Antonio Road: 6.63754km
San Francisco Bay Trail: 24.6621km
South Bernardo Avenue: 5.50634km
South Mary Avenue: 5.36766km
South Wolfe Road: 5.11473km
Southbay Freeway: 18.4306km
Stevens Creek Trail: 7.93549km
Sunnyvale-Saratoga Road: 6.53507km
West El Camino Real: 23.4789km
West Fremont Avenue: 5.03967km
West Middlefield Road: 7.24211km
West Tasman Drive: 6.29783km
```

### Checkout
youtu.be/FBD-dFzEe7I (Links to an external site.)
for a video explanation of the data format, requirements, and an example worked out manually!

### Submission
This may come as a surprise, but you will upload your code to Grade Oven. I'll update this section when Grade Oven is ready.

#### Data Format
Output to a file named `output.txt` with the following format in plain-text (similar to the input):

The first line should have the total length of all the roads we're rebuilding in kilometers as a floating point number, e.g. `314.1592`.

The second line should have the total number of edges we're rebuilding, e.g. `1234`.

Every other line should contain an edge (part of a road) we're rebuilding, represented as two OSM IDs (for the two nodes that make up the edge) with a single space between them, e.g. `1234567 567890`. The edges can be in any order.