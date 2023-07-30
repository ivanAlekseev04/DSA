#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> g;
vector<int> components;
int color = 0;

void dfsUtil(int vertex) {
    visited[vertex] = true;
    components[color]++;
    
    for(auto it : g[vertex]) {
        if(!visited[it]) {
            dfsUtil(it);
        }
    }
}

void dfs(int v) {
    visited = vector<bool>(v, false);
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfsUtil(i);
        }
        
        color++;
    }
}

int main() {
    int v, e, sizeOfGroup;
    
    cin >> v >> e >> sizeOfGroup;
    
    g = vector<vector<int>>(v, vector<int>());
    components = vector<int>(v, 0);
    
    int from, to;
    for(int i = 0; i < e; i++) {
        cin >> from >> to;
        
        g[from].push_back(to);
        g[to].push_back(from);
    }
    
    dfs(v);
    
    int counter = 0;
    for(auto it : components) {
        if(it % sizeOfGroup == 0 && it != 0) {
            counter++;
        }
    }
    
    cout << counter << '\n';
}
