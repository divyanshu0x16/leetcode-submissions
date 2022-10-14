- If the graph has no cycle, then such a graph is always bipartite. Done using DFS.

- Not necessary that if a graph has no cycle, it will not be bipartite. 
- If the cycle has even no. of nodes, then the graph can be bipartite, but if the no. of nodes in cycle is odd, then the graph cannot be bipartite.

Our color array basically has 3 states. It tells whether the node has been colored, if colored then whether it is the 1st color or 2nd one.  In the checkBipartite function, we are initializing the color array with -1(not yet colored). We can use the color array to check whether a node is visited or not (we don’t need a separate visited array). 

Then we are checking whether the node is colored or not. If it is not colored, we are coloring with the opposite color of its neighbor. That is, 1 – color[node], gives 1 if the color[node] is 0 and 0 if the color[node] is 1. This is how we are inverting the color of the adjacencies. 