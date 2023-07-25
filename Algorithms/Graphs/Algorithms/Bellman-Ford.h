#include <bits/stdc++.h>
using namespace std;

struct Connection {
    int from;
    int to;
    int weight;

    Connection() : from(0), to(0), weight(0) {}
    Connection(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

int E, V, startEdge;
vector<Connection> adj;
vector<int> distances;

bool bellmanFord() {
    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int from = adj[j].from;
            int to = adj[j].to;
            int weight = adj[j].weight;

            if(distances[to] > distances[from] + weight) {
                distances[to] = distances[from] + weight;
            }
        }
    }

    
    for(int j = 0; j < E; j++) {
        int from = adj[j].from;
        int to = adj[j].to;
        int weight = adj[j].weight;

        if(distances[to] > distances[from] + weight) {
            return false;
        }
    }

    return true;
}
void printDistances() {
    for(int i = 0; i < V; i++) {
        cout << "From: " << startEdge << " To: " << i << " Weight: " << distances[i] << '\n';
    }
}

int main() {
    cin >> V >> E;

    int from, to, weight;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight;
        adj.push_back(Connection(from, to, weight));
    }

    cin >> startEdge;

    distances = vector<int>(V, INT32_MAX);
    distances[startEdge] = 0;

    if(bellmanFord()) {
        printDistances();
    } else {
        cout << "Graph contains negative cycle\n";
    }
}

/*

V = 5
E = 8

0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

startEdge = 0

Result:

VERTEX    DISTANCE
0          0
1          -1
2          2
3          -2
4          1

*/
