#include <bits/stdc++.h>
using namespace std;

int E, V;
unordered_map<int, unordered_set<int>> adj;

void dfsUtil(int val, vector<bool>& visited) {
    visited[val] = true;

    for(auto it : adj[val]) {
        if(!visited[it]) {
            dfsUtil(it, visited);
        }
    }

    cout << val << endl; 
}

void dfs() {
    vector<bool> visited(E, false);

    for(int i = 0; i < E; i++) {
        if(!visited[i]) {
            dfsUtil(i, visited);
        }
    }
}

int main() {
    cin >> E >> V;

    for(int i = 0; i < E; i++) 
        adj.insert(make_pair(i, unordered_set<int>()));

    for(int i = 0, from = 0, to = 0; i < V; i++) {
        cin >> from >> to;
        adj[from].insert(to);
        // adj[to].insert(from); // Uncomment to make graph *undirected*
    }

    dfs();
}

/*
9 12
0 5
0 3
5 1
1 3
3 5
3 2
2 6
4 6
4 3
6 0
7 0
0 8
*/
