#include <bits/stdc++.h>
using namespace std;
                        // *Undirected graph
int E, V;
unordered_map<int, vector<pair<int, int>>> adj; // not "unordered_map<int, unordered_map<int, int>>" because it can exist multiple edges between 2 vertices
vector<int> distances;

void dijikstra(int startEdge) {    
    distances = vector<int>(V, INT32_MAX);
    distances[startEdge] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // std::greater will make min_heap according to the 1 parameter in std::pair
    
    pq.push(make_pair(0, startEdge));

    while(!pq.empty()) {
        int curEdge = pq.top().second;
        int curWeight = pq.top().first;
        
        pq.pop();

        if(curWeight > distances[curEdge]) // Optimization trick
            continue;

        for(auto it : adj[curEdge]) {
            int nextEdge = it.first;
            int weightToNext = it.second;

            if(distances[nextEdge] > distances[curEdge] + weightToNext) {
                distances[nextEdge] = distances[curEdge] + weightToNext;
                
                pq.push(make_pair(distances[nextEdge], nextEdge));
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
