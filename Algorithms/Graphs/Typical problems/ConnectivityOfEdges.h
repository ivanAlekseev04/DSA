// Task: https://www.hackerrank.com/contests/sda-hw-10-2022/challenges/challenge-2852/submissions/code/1364640224

#include <bits/stdc++.h>
using namespace std;

int E, V;
unordered_map<int, unordered_set<int>> adj;
vector<int> levels;

void dfsUtil(int val, vector<bool>& visited, int level) {
    visited[val] = true;
    levels[val] = level;

    for(auto it : adj[val]) {
        if(!visited[it]) {
            dfsUtil(it, visited, level);
        }
    }

    cout << val << endl; 
}
void dfs() {
    vector<bool> visited(E, false);

    for(int i = 1; i < (E + 1); i++) {
        if(!visited[i]) {
            dfsUtil(i, visited, i);
        }
    }
}

int main() {
    cin >> E >> V;

    for(int i = 1; i < (E + 1); i++) 
        adj.insert(make_pair(i, unordered_set<int>()));

    for(int i = 0, from = 0, to = 0; i < V; i++) {
        cin >> from >> to;
        adj[from].insert(to);
    }

    levels = vector<int>(E + 1, false);

    dfs();

    int K;
    cin >> K;

    int from, to;
    for(int i = 0; i < K; i++) {
        cin >> from >> to;

        if(levels[from] == levels[to]) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
}
