# Quiz 10: Graphs

## 1. Graph Representation
Let V be the number of vertices/nodes in a graph and E be the number of edges.

What's the big-O of memory used by the adjacency list representation (e.g. a map of nodes to edges)?

What's the big-O of memory used by the matrix representation?

### answer
**adjacency_list**

$O(v + E)$, where *v* is a vertex and E is an edge.

**matrix**

$O(v^2)$

## 2. Dijkstra's Algorithm
Dijkstra's Algorithm* only gives one shortest path from some starting node to some destination node. Explain how we can modify the algorithm to return all shortest paths.

*The version that I implemented in lecture.

### answer
We can return a vector of paths: `vector< vector<Node> > paths;` modify the if statement 
```cpp
if (entry.path_weight < min_weight[entry.node])
```
to 
```cpp
if (entry.path_weight <= min_weight[entry.node])
```
and we remove this if statement.
```cpp
if (entry.node == destination) { // we can break early.
    break;
}
```
After that we allow the `prev_node` map to be able to store multiple previous nodes by declaring it like this: `map<Node, vector<Node>>` prev_nodes.

then at the end of the while loop we traverse over `prev_nodes` following the path back to the starting node for each for each node in the vector, and recursively follow the path back to the previous node vectors. After we store the path in a vector, we reverse the path then push the entire vector to a vector of vectors name `paths` and return to the end of the stack to traverse the other previous nodes for destination. After all of this is done, we return `paths`.



## 3. Maximum Spanning Tree
Minimum Spanning Trees are nice but I want more. Describe an algorithm for finding a Maximum Spanning Tree. How is it different than finding a Minimum Spanning Tree?

### answer
to find a minimum spanning tree, we use a greedy algorithm that traverses the adjacent vertex that has the least weight all of all the adjacent vertices, we can use the same greedy algorithm but instead of traversing the least weight that an edge has, we traverse the edge with the most weight.

## 4. Farthest Node
Given a weighted graph (with non-negative weights) and a starting node, how would you find the node that is farthest away (no matter what path you take)?

### answer
run Dijkstras algorithm for the whole graph until all nodes are visited, giving us the shortest path to every node, which also fills up the min_weight map. After that, we traverse over the min_weight map to find the Node with the largest weight value, then just return that Node.


```cpp
WeightedStringGraph::Node dijkstras(WeightedStringGraph& graph, const WeightedStringGraph::Node& start, const WeightedStringGraph::Node& destination) {
    typedef WeightedStringGraph::Node Node;
    map<Node, double> min_weight;
    map<Node, Node> prev_node;
    // Creating Table.
    for (const auto& node_edges_pair : graph.edges) {
        const Node node = node_edges_pair.first;
        min_weight[node] = numeric_limits<double>::infinity();
        // if the prev_node[x] == node, that's how we indicate that there is no previous node.
        prev_node[node] = node;
    }
    // Priority Queue, with priority being the distance.
    priority_queue<DijkstrasQueueEntry> q;
    q.emplace(start, start, 0);
    while (!q.empty()) {
        // Get the next entry to populate
        const DijkstrasQueueEntry entry = q.top();
        q.pop();
        // Process that entry and adding new paths.
        // Check if the entry corresponds to a new shorter path or not.
        if (entry.path_weight < min_weight[entry.node]) {
            min_weight[entry.node] = entry.path_weight;
            prev_node[entry.node] = entry.prev_node;

            for (const WeightedStringGraph::Edge& edge : graph.edges[entry.node]) {
                q.emplace(edge.dst, entry.node, entry.path_weight + edge.weight);
            }
        }
    }
    double max_min_weight = 0.0;
    Node * furthest_node = nullptr;
    for (const auto values : min_weight) {
        if (max_min_weight < values.second) {
            max_min_weight = values.second;
            furthest_node = &(values.first);
        }
    }
    return *furthest_node;
}
```