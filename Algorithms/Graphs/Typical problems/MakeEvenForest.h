// Task: https://www.hackerrank.com/contests/test6-sda/challenges/challenge-1761

#include <bits/stdc++.h>
using namespace std;

int E, V;
unordered_map<int, vector<int>> adj;
vector<int> visited;

int dfs(int from, int& edgesToRemove) {
    visited[from] = true;

    int curTreeNodesCount = 0;

    for(auto it : adj[from]) {
        if(!visited[it]) {
            int subTreeNodesCount = dfs(it, edgesToRemove);

            if(subTreeNodesCount % 2 == 0) {
                edgesToRemove++;
            } else {
                curTreeNodesCount += subTreeNodesCount;
            }
        }
    }

    return (curTreeNodesCount + 1);
}

int makeEvenForest() {
    visited = vector<int>(V + 1, false);
    
    int edgesToRemove = 0;
    dfs(1, edgesToRemove);

    return edgesToRemove; 
}

int main() {
    cin >> V >> E;

    int from, to;
    for(int i = 0; i < E; i++) {
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    } 

    cout << makeEvenForest() << '\n';
}
