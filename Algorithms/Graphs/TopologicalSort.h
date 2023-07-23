#include <bits/stdc++.h>
using namespace std;

int E, V;
unordered_map<int, unordered_set<int>> adj;

void topologicalSortUtil(int val, vector<bool>& visited, stack<int>& toPrint) {
    visited[val] = true;

    for(auto it : adj[val]) {
        if(!visited[it]) {
            topologicalSortUtil(it, visited, toPrint);
        }
    }

    toPrint.push(val);
}

void topologicalSort() {
    vector<bool> visited(E, false);
    stack<int> toPrint;

    for(int i = 0; i < E; i++) {
        if(!visited[i]) {
            topologicalSortUtil(i, visited, toPrint);
        }
    }

    while(!toPrint.empty()) {
        cout << toPrint.top() << '\n';
        toPrint.pop();
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

    topologicalSort();
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
