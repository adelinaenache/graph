#include "Graph.h"
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"

Graph::Graph() : nodes(0), edges(0) {}
Graph::Graph(unsigned _nodes, Vector<Pair> edgesPairs) : nodes(_nodes), edges(0) {
    addNode();
    for (int i = 1; i <= _nodes; i++) {
        addNode();
    }
      
    for (int index = 0; index < edgesPairs.length(); index++) {
        addEdge(edgesPairs[index]);
    }
}

Graph::Graph(const Graph &other): nodes(other.nodes), edges(other.edges), adj(other.adj) {}
Graph::~Graph() {
    Vector <int> dummy;
    for (int index = 0; index < this->nodes; index++) {
        adj[index].resize(0, 0);
    }
    adj.resize(0, dummy);
    this->edges = this->nodes = 0;
}

void Graph::addNode() {
    Vector <int> v;
    adj.push_back(v);
    nodes++;
}

void Graph::addEdge(Pair pair) { // assume that it's and undirected graph
    adj[pair.first()].push_back(pair.second());
    adj[pair.second()].push_back(pair.first());
    edges++;
}

unsigned Graph::getNodes() const {
    return nodes;
}

unsigned Graph::getEdges() const {
    return edges;
}

bool Graph::isTree() const {
    return getNodes() == (getEdges() + 1);
}


Vector<int> Graph::dfs(int start) {
    Vector<int> sol;
    bool *visited = new bool(false);
    dfsUtil(start, visited, sol);
    return sol;
}

void Graph::dfsUtil(int k, bool *visited, Vector<int>&sol) {
    sol.push_back(k);
    visited[k] = true;
    for (int i = 0; i < adj[k].length(); i++) {
        if (!visited[adj[k][i]]) {
            dfsUtil(adj[k][i]);
        }
    }
}

unsigned countConex() const {
    int sol = 0;
    Vector<int> parc;
    bool *visited = new bool(false);

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            sol++;
            dfsUtil(i, visited, parc);
        }
    }

    return sol;
}

Vector<Pair> Graph::bfs(int start) const {
    Vector<Pair> sol;
    Queue q;
    sol.push_back(Pair(start, 0));
    q.push(0); // Ill keep in queue current node's position in 
            // the solutions vector because i want access to
            // the distance from start node
            // and queue is only implemented for integers.
    bool *visited = new bool(false);
    visited[start] = true;

    while(!q.isEmpty()) {
        int pos = q.peek();
        int node = sol[pos].first();
        q.pop();
        
        for (int i = 0; i < adj[node].length(); i++) {
            if (!visited[adj[node][i]]) {
                visited[adj[node][i]] = true; // mark current node visited
                sol.push_back(Pair(adj[node][i], sol[pos].second() + 1)); // push Pair(current_node, updated_distance)
                q.push(sol.length() - 1);  // push sol current position
            }
        }

    }
    return sol;
}

Graph& Graph::operator=(const Graph& o) {
    Vector <int> dummy;
    for (int index = 0; index < this->nodes; index++) {
        adj[index].resize(0, 0);
    }
    adj.resize(0, dummy);

    this->adj = o.adj;
    this->edges = o.edges;
    this->nodes = o.nodes;
    return *this;
}


unsigned Graph::distance(int start, int stop) const {
    Vector <Pair> sol = bfs(start); // run bfs starting from the first node
    for (int i = 0 ; i < sol.length(); i++) { //search "stop" node in the solution
        if(sol[i].first() == stop) {
            return sol[i].second(); // return distance;
        }
    }
    return 0; // return 0 if the node is not found
} 