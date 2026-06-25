#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <exception>
#include <cassert>
using namespace std;

class MyException : public exception {
    const char* msg;
public:
    MyException(const char* msg) : msg(msg) {}

    const char* what() const noexcept {
        return msg;
    }
};
/*
nodes.txt
- first line in nodes contains 4 doubles: min x coord, min y coord, max x coord, max y coord
- every other line represents a 2D point which have 3 parts: 
    - a int_least64_t OSM ID that iniquely identifies that node
    - a double x coordinate
    - and a double y coordinate.
*/

typedef int_least64_t OSMID;

struct Node {
    OSMID id;
    double x;
    double y;
};
/*
roads.txt
Every line has 3 main parts:
    - a int_least64_t OSM ID that uniquely identifies that part of a road
    - a list of Node ID's 
        - the number of nodes, N, that make up that part of the road (in order)
        - N OSM IDs that for the nodes
    - The name of the road

Note that the same road may show up multiple times because it has multiple parts.

N nodes has N - 1 edges.
    - the nodes are undirected.
*/

/*

output.txt
    total_length of all the roads in km
    number_of_edges
    output all of the edges using the node_id so if an edge connects nodeId 11 and 12, output: it doesn't matter which order it's in. It can be 12 11 instead.
        11 12
        11 33
        44 55
        55 66
        77 44
*/
struct Road {
    vector<int_least64_t> path;
    string road_name;
};

map<OSMID, Node> load_nodes(const string& filename) {
    ifstream nodes_file(filename);
    if (nodes_file.bad() || nodes_file.fail()) {
        throw MyException("Error opening nodes file.");
    }

    map<OSMID, Node> nodes;
    double min_x, max_x;
    double min_y, max_y;

    nodes_file >> min_x >> min_y >> max_x >> max_y;

    while (nodes_file.good()) {
        OSMID osmid;
        double x, y;
        Node n;
        nodes_file >> osmid >> x >> y;
       
        n.x = x;
        n.y = y;
        n.id = osmid;
        if (nodes_file.good()) {
            nodes[osmid] = { n };
        }
    }
    if (nodes_file.bad()) {
        throw MyException("Error reading nodes from file.");
    }
    nodes_file.close();
    return nodes;
}


map<OSMID, Road> load_roads(const string& filename) {
    map<OSMID, Road> roads;
    ifstream roads_file(filename);
    if (roads_file.bad() || roads_file.fail()) {
        throw MyException("Error Opening roads file");
    }
    long num_roads = 0;

    while (roads_file.good()) {
        OSMID osmid;
        int path_len;
        roads_file >> osmid >> path_len;
        if (roads_file.good()) {
            Road r;
            r.path.reserve(path_len);
            for (int i = 0; i < path_len; ++i) {
                OSMID node_id;
                roads_file >> node_id;
                ++num_roads;
                r.path.push_back(node_id);
            }
            roads_file.get(); // Read the extra space
            getline(roads_file, r.road_name);
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
    return sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) );
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

map<string, double> get_road_lengths(const map<OSMID, Node> & nodes, const map<OSMID, Road> & roads) {
    map<string, double> road_lengths;
    for (const auto& osmid_road : roads) {
        const Road& road = osmid_road.second;
        road_lengths[road.road_name] += get_road_length(nodes, road);
    }
    return road_lengths;
}

pair<double, pair<Node,Node>> find_largest_edge_in_road(map<OSMID, Node> nodes, Road road) {
    double max_dist = 0, len = 0;
    Node n1, n2;
    for (int i = 1; i < road.path.size(); ++i) {
        const Node& a = nodes.find(road.path[i - 1])->second;
        const Node& b = nodes.find(road.path[i])->second;
        len = distance(a, b);
        if (len > max_dist) {
            n1 = a; n2 = b;
            max_dist = len;
        }
    }

    return make_pair(max_dist, make_pair(n1, n2));
}

double total_length(map<OSMID, Node> nodes, map<OSMID, Road> roads, map<string, double> road_lengths) {
    // Implement a minimum spanning tree, this does not work for the homework.
    map<string, double> subtracting_dist;
    for (const auto & road : roads) {
        double max_dist = find_largest_edge_in_road(nodes, road.second).first;
        if (subtracting_dist[road.second.road_name] < max_dist) {
            subtracting_dist[road.second.road_name] = max_dist;
        }
    }
    double total_length = 0;
    for (const auto x : road_lengths) {
        total_length += x.second - subtracting_dist[x.first];
    }
    return total_length;
}

int total_edges(map<OSMID, Road> roads) {
    // You will delete multiple edges in a road, you may not delete any edges in a road aswell.
    int total_edges = 0;
    map<string, int> road_path_size;
    for (const auto& r : roads) {
        road_path_size[r.second.road_name] += r.second.path.size() - 1;
    }
    for (const auto& x : road_path_size) {
        total_edges += x.second - 1;
    }
    return total_edges;
}

void printing_edges(map<OSMID, Node> nodes, map<OSMID, Road> roads, map<string, double> road_lengths) {
    map< string, pair<Node, Node> > deleted_edges;
    for (const auto& r : roads) {
        const OSMID a = find_largest_edge_in_road(nodes, r.second).second.first.id;
        const OSMID b = find_largest_edge_in_road(nodes, r.second).second.second.id;
        vector<int_least64_t> path(r.second.path);
        cout << "\t" << r.second.road_name << " path:" << endl;
        for (int i = 0; i < path.size() - 1; ++i) {
            
            if (a != nodes[path[i]].id && b != nodes[path[i + 1]].id) {
                cout << path[i] << " " << path[i + 1] << endl;
            }
        }
    }
}

void print_output(map<OSMID, Node> nodes, map<OSMID, Road> roads, map<string, double> road_lengths) {
    // find an edge to delete, n nodes have n - 1 edges. Delete the largest node, if they are all the same size, you can delete anyone of them.
    
    // Find total_length of all the roads in km;
    cout << total_length(nodes, roads, road_lengths) << endl;
    // Find the number of total_edges
    cout << total_edges(roads) << endl;
    // output all of the edges using the node_id so if an edge connects nodeId 11 and 12, output: it doesn't matter which order it's in. It can be 12 11 instead.
    printing_edges(nodes, roads, road_lengths);
}       
/*
output.txt
    total_length of all the roads in km
    number_of_edges
    output all of the edges using the node_id so if an edge connects nodeId 11 and 12, output: it doesn't matter which order it's in. It can be 12 11 instead.
        11 12
        11 33
        44 55
        55 66
        77 44
*/
int main(int argc, char *argv[]) {
    try {
        const double min_road_len = 5; // km
        map<OSMID, Node> nodes = load_nodes(argc > 1 ? argv[1] : "nodes.txt");
        map<OSMID, Road> roads = load_roads(argc > 2 ? argv[2] : "roads.txt");

        map<string, double> road_lengths = get_road_lengths(nodes, roads);

        print_output(nodes, roads, road_lengths);
    } catch (MyException e) {
        cerr << e.what() << endl;
    }
    system("pause");
}
