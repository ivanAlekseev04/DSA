#include <bits/stdc++.h>
using namespace std;

int E, V;
unordered_map<int, unordered_set<int>> adj;

void bfsUtil(int val, vector<bool>& visited) {
    visited[val] = true;

    queue<int> toTraverse;
    toTraverse.push(val); 

    while(!toTraverse.empty()) {
        int val = toTraverse.front();
        toTraverse.pop();
        cout << val << endl;

        for(auto it : adj[val]) {
            if(!visited[it]) {
                visited[it] = true;
                toTraverse.push(it);
            }
        }
    }
}

void bfs() {
    vector<bool> visited(E, false);

    for(int i = 0; i < E; i++) {
        if(!visited[i]) {
            bfsUtil(i, visited);
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

    bfs();
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
