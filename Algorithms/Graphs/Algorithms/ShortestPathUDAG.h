#include <bits/stdc++.h>
using namespace std;

const int UNINITIALIZED = -1;

int E,V; // vertices "V" will start from number 1 
vector<vector<int>> adj;
vector<int> distances;

void intializeGraph() {
    int from, to;
    for(int i = 0; i < E; i++) {
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

void bfs(int from) {
    vector<bool> visited(V, false);
    queue<pair<int, int>> toTraverse;

    visited[from] = true;
    toTraverse.push(make_pair(from, 0));

    while(!toTraverse.empty()) {
        int vertex = toTraverse.front().first;
        int traversed = toTraverse.front().second;

        visited[vertex] = true;
        toTraverse.pop();

        if(distances[vertex] == UNINITIALIZED)
            distances[vertex] = traversed;

        for(auto it : adj[vertex]) {
            if(!visited[it]) {
                toTraverse.push(make_pair(it, traversed + 1));
            }
        }
    }
}

int main() {
    cin >> V >> E;

    adj = vector<vector<int>>(V, vector<int>());
    distances = vector<int>(V, UNINITIALIZED);

    intializeGraph();
    
    int from;
    cin >> from;

    bfs(from);

    return 0;
}
   
/*
V = 8
E = 10

2 1
1 0
0 3
3 7
3 4
7 6
4 6
4 5
4 7
5 6
*/
