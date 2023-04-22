# data-structure-graph-list

Created by Brian Chairez

This C++ project implements the graph data structure using a std::list of user defined nodes.
This implementation is both unweighted and directed, meaning there are no weights/costs associated with node edges and each node edge is one-way and must be directly specified.
The list of nodes acts as the adjacency list and each node in the list contains it's data and another list that acts as it's respective edge list.

Both the adjacency list and the edge list are implemented using raw pointers.
This is done so the adjacency list can call "new" (as well as "delete" to memory manage) to create the new nodes when needed and so the edge list can simply point to the respective node that has been already created to save space.

Current Issue: erase_neighbors() function when deleting a node vertex from the adjacency list does not function corrently. Only if the very first neighbor in a vertex's edge list is the corresponding node will it successfully remove. Neighbors located in the middle or the end of the edge list do not get removed.
