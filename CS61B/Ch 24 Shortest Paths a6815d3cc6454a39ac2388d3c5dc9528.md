# Ch 24. Shortest Paths

## Shortest Paths

Note that we’ve already developed an algorithm that finds us the shortest path, but only for graphs with no edge labels (no edge weights). Recall that BFS gives the shortest path where shortest means that least amount of edges traversed. 

But what about for graphs with edge labels? We need to develop a new algoirthm for this.

Note the fact that the shortest paths tree from a source `s` can be created in the following way:

- For every vertex `v` (which is not `s`) in the graph, find the shortest path from `s` to `v`.
- “Combine/ Union” all the edges that you found above.

Moreover, the Shortest Path will ************************************always be a tree.************************************ Why? recall the `edgeToedgeTo` array, every vertex has exactly one “parent”. Since there are $v$ vertices, each vertex has exactly one parent except that starting vertex, so there are $v- 1$ edges.

## Dijkstra’s Algorithm

In one sentence: visit vertices in **order of best-known distance** from source. On visit, ***************relax*************** every edge from the visted vertex.

**Proof of Dijkstras:** 

Dijkstras is guaranteed to return a correct result if all edges are non-negative.

- Proof relies on the property that relaxation always fails on edges to visited vertices.

Proof: 

At start, distTo[source] = 0, which is optimal

After relaxing all edges from source, let vertex v1 be the vertex with minimum weight, i.e. that is closest to the source. Claim: distTo[v1] is optimal, and thus future relaxation on v1 will fail. Why?

- distTo[p] ≥ distTo[v1] for all p where v1 and p are adjacent, therefore
- distTo[p] + w ≥ distTo[v1]

## Dijkstra’s Algorithm Runtime

Priority Queue operation count, assuming binary heap based PQ:

- Add: V, each costing O(log V) time.
- RemoveSmallest: V, each costing O(log V) time.
- Change Priority: E, each costing O(log V) time.

Overall runtime: O(V * log(V) + V*log(V) + E*log(V))

- Assuming E > V, this is just O(E log V) for a connected graph.

## A* Algorithm

What if we only want to find the shortest path from a source node a specific target node (like from Denver to New York)? Dijkstra’s would be inefficient for this task because it would explore many edges that we don’t care about (e.g. when routing from Denver to NYC, we’d explore everything within more than a thousand miles in all directions before reaching NYC.)

To fix this, we make a minor change to Dijkstra’s where instead of visiting vertices where their priority is the smallest distance from the source node, the priority for is now **********bestKnownDistToV + estimateFromVToGoal********** as our heuristic.

Simple Idea:

- visit vertices in order of dist(source, v) + h(v, goal), where h(v, goal) is an estimate of the distance from v to our target node.
- In other words, look at some location v if:
    - We already know the fastest way to reach v.
    - AND we suspect that v is also the fastest way to NYC taking into account the time to get to v.

## Questions

1. What is a graph with no edge labels?
    1. edge labels are edge weights. BFS gives us shortest paths for only graphs that have no edge labels