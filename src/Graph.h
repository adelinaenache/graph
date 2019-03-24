#ifndef _GRAPH_H
#define _GRAPH_H

#include "Vector.h"
#include "Pair.h"

class Graph {
    unsigned nodes; // number of nodes
    unsigned edges; //number of edges;
    Vector<Vector<int> > adj; // adj list;
public:
    Graph();
    Graph(unsigned, unsigned);
    Graph(unsigned, Vector<Pair>);
    Graph(const Graph&);
	Graph& operator=(const Graph& o);
	Graph& operator>(const Graph&);
    Graph& operator<(const Graph&);

    ~Graph();

    void addNode();
    void addEdge(Pair);

    Vector<Pair> bfs(int) const; // return pairs of (node, distance from start)
    Vector<int> dfs(int) const; // return Vector of visited nodes

    unsigned distance(int, int) const; // return distance
    unsigned countConex() const;

    unsigned getNodes() const;
    unsigned getEdges() const;
    bool isTree() const;

private:
    void dfsUtil(int, bool, Vector<int>&);

};
#endif // _GRAPH_H