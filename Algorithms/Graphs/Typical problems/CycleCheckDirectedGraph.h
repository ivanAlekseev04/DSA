#pragma once

#include <bits/stdc++.h>
using namespace std;

int E, V; 
vector<vector<int>> adj; // Actual graph

bool isCyclic = 0;
vector<bool> visited; // Keep track of already visited vertices
vector<bool> stackTrack; // Keep track of current recursion stack

void intializeGraph() {
    adj = vector<vector<int>>(V, vector<int>());

    int from, to, weight;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight; // There is no need of "weight" here

        adj[from].push_back(to); 
    }
}
void dfsUtil(int from) {
    if(!visited[from]) {

        visited[from] = true;
        stackTrack[from] = true; // Adding vertex to current recursion stack

        for(auto it : adj[from]) {
            if(!visited[it]) { 
                dfsUtil(it);
            } else if(stackTrack[it]) {
                isCyclic = true;
            }
        }
    }

    stackTrack[from] = false; // Remove from current recursion stack
}
void dfs() {
    visited = vector<bool>(V, false);   
    stackTrack = vector<bool>(V, false);

    isCyclic = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i])
            dfsUtil(i);

        if(isCyclic)
            break;
    }
}

int main() {
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++) {
        cin >> V >> E;

        intializeGraph();
        
        dfs();
        cout << boolalpha << isCyclic << " ";
    }
    
    cout << '\n';
}

/*

1
8 7
0 1 2 // {1} first component
0 2 5 // {1} 
2 3 6 // {1}
4 5 8 // {2} second component
4 6 7 // {2} 
7 6 4 // {2}
7 4 9 // {2}

*/
