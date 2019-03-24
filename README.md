# Graph 

C++ Graph implementaion. 

### Build & run 

```
cd graph
make all 
./build/graph
```

### Notes

Because I wanted to implement a general Graph class I wanted to be able to add a new node in the graph, so I needed an resizable lis of lists. The handy solution was to define a "Vector" template, which would allow me to have a Vector of Vector `Vector< Vector <int> >`.

### >> operator

Reads a graph in the following format 
```
no_nodes no_muchii
node1 node2
node3 node4  
....

nodeK nodeP
```


### << operator

Writes a graph in the following format 
```
no_nodes no_muchii
node1 node2
node3 node4  
....

nodeK nodeP
```

### Mentions 
* nodes start from 0 
* functionality is displayed in main.cpp
* the program reads & writes an graph - input from keyboward needed


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