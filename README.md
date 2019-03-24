# Graph 

C++ Graph implementaion. 


### Functionality

* bfs 
* dfs
* count conex components
* check if the given graph is tree
* count distance between two nodes
* override = operator
* override > and < operators
* override >> and << operators
* [] returns the adjacency list of the node

### Notes

Because I wanted to implement a general Graph class I wanted to be able to add a new node in the graph, so I needed an resizable lis of lists. The handy solution was to define a "Vector" template, which would allow me to have a Vector of Vector `Vector< Vector <int> >`.

