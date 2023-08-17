#include <bits/stdc++.h>
using namespace std;
                        // *Undirected graph
struct Edge {
    int edge;
    int weight;

    Edge() : edge(0), weight(INT32_MAX) {}
    Edge(int edge, int weight) : edge(edge), weight(weight) {}
};

struct cmp {
    bool operator()(const Edge& f, const Edge& s) const {
        return f.weight > s.weight;
    }
};

int E, V;
unordered_map<int, vector<pair<int, int>>> adj; // not "unordered_map<int, unordered_map<int, int>>" because it can exist multiple edges between 2 vertices
vector<int> distances;

void dijikstra(int startEdge) {    
    distances = vector<int>(V, INT32_MAX);
    distances[startEdge] = 0;

    priority_queue<Edge, vector<Edge>, cmp> pq;
    
    pq.push(Edge(startEdge, 0));

    while(!pq.empty()) {
        Edge minimal = pq.top();
        pq.pop();

        if(distances[minimal.edge] < minimal.weight) // Optimization trick
            continue;

        for(auto it : adj[minimal.edge]) {
            int weight = it.second;
            int edge = it.first;

            if(distances[edge] > distances[minimal.edge] + weight) {
                distances[edge] = distances[minimal.edge] + weight;
                pq.push(Edge(edge, distances[edge]));
            }
        }
    }
}

int main() {
    cin >> V >> E;

    int from, to, weight;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight;
        
        adj[from].push_back(make_pair(to, weight));
        adj[to].push_back(make_pair(from, weight));
    } 

    int startVert;
    cin >> startVert;

    dijikstra(startVert);

    for(int i = 0; i < V; i++) {
        if(i != startVert) 
            cout << "Vertex: " << i << " Distance: " << distances[i] << '\n';
    }
}

/*
V = 9
E = 14

0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
