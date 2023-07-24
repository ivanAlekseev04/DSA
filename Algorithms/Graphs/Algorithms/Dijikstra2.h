#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int edge;
    int weight;

    Edge() : edge(0), weight(INT32_MAX) {}
    Edge(int edge, int weight) : edge(edge), weight(weight) {}
};

class cmp {
    public:
        bool operator()(Edge& f, Edge& s) {
            return f.weight > s.weight;
        }
};

int E, V;
unordered_map<int, unordered_map<int, int>> adj;
vector<int> distances;

void dijikstra(int startEdge) {    
    distances = vector<int>(E, INT32_MAX);
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
    cin >> E >> V;

    for(int i = 0; i < E; i++)
        adj.insert(make_pair(i, unordered_map<int, int>()));

    int from, to, weight;
    for(int i = 0; i < V; i++) {
        cin >> from >> to >> weight;
        adj[from][to] = weight;
        adj[to][from] = weight;
    } 

    int startVert;
    cin >> startVert;

    dijikstra(startVert);

    for(int i = 0; i < E; i++) {
        if(i != startVert) 
            cout << "Vertex: " << i << " Distance: " << distances[i] << '\n';
    }
}

/*
E = 9
V = 14

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
