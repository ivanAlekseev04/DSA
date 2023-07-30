#include <bits/stdc++.h>
using namespace std;

int E,V;

vector<vector<int>> adj;
vector<int> path;

vector<bool> forbiddenByOrder;  
vector<bool> forbiddenByClause;  

void intializeGraph() {
    int from, to;
    for(int i = 0; i < E; i++) {
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}
void initializePath() {
    int pathLength;
    cin >> pathLength;
    path = vector<int>(pathLength);

    int toAdd;
    for(int i = 0; i < pathLength; i++) {
        cin >> toAdd;
        path[i] = toAdd;
        
        if(i >= 2)
            forbiddenByOrder[toAdd] = true;
    }
}
void initializeForbiddenByClause() {
    int forbiddenCount;
    cin >> forbiddenCount;

    int vertex;
    for(int i = 0; i < forbiddenCount; i++) {
        cin >> vertex;

        forbiddenByClause[vertex] = true;
    }
}

bool bfsUtil(int from, int to, int& pathWeight) {
    vector<bool> visited(V + 1, false);
    queue<pair<int, int>> toTraverse;

    visited[from] = true;
    toTraverse.push(make_pair(from, 0));

    while(!toTraverse.empty()) {
        int vertex = toTraverse.front().first;
        int traversed = toTraverse.front().second;

        visited[vertex] = true;
        toTraverse.pop();

        for(auto it : adj[vertex]) {
            if(it == to) {
                pathWeight += traversed + 1;
                return true;
            }

            if(!visited[it] && !forbiddenByClause[it] && !forbiddenByOrder[it]) {
                toTraverse.push(make_pair(it, traversed + 1));
            }
        }
    }

    return false;
}
int bfs() {
    int pathWeight = 0;

    for(int i = 0; i < path.size() - 1; i++) {
        if(!bfsUtil(path[i], path[i + 1], pathWeight))
            return -1;

        if(i + 2 < path.size())
            forbiddenByOrder[path[i + 2]] = false;     
    }

    return pathWeight;
}

int main() {
    cin >> V >> E;

    adj = vector<vector<int>>(V + 1, vector<int>());
    forbiddenByClause = vector<bool>(V + 1, false);
    forbiddenByOrder = vector<bool>(V + 1, false);

    intializeGraph();
    initializePath();
    initializeForbiddenByClause();
    
    cout << bfs() << '\n';
}
