// Idea of task: edge's initial neighbours are all other edges to which it doesn't have a path(kind of negation)
// https://www.hackerrank.com/contests/sda-hw-10-2022/challenges/challenge-3782/copy-from/1364661770

#include <bits/stdc++.h>
using namespace std;

struct Elem {
    int edge;
    int traversedCount;

    Elem() : edge(1), traversedCount(0) {}
    Elem(int edge, int traversedCount) : edge(edge), traversedCount(traversedCount) {}
};

int E, V;
int counter = 1; // counter need to be "1", because we don't need to calculate distance from parent to itself
unordered_map<int, unordered_set<int>> notToVisit;
vector<int> distances;

void bfs(int startEdge) {
    vector<bool> visited(E + 1, 0);
    
    queue<Elem> toTraverse;
    visited[startEdge] = true;
    toTraverse.push(Elem(startEdge, 0));

    while(!toTraverse.empty()) {
        Elem toCheck = toTraverse.front();
        toTraverse.pop();

        for(int i = 1; i < (E + 1); i++) {
            if(counter == E)
                return;
            
            if(!visited[i] && notToVisit[toCheck.edge].find(i) == notToVisit[toCheck.edge].end()) {
                visited[i] = 1;
                toTraverse.push(Elem(i, toCheck.traversedCount + 1));
                distances[i] = toCheck.traversedCount + 1;
                counter++;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++) {
        cin >> E >> V;

        distances = vector<int>(E + 1, -1);
        notToVisit = unordered_map<int, unordered_set<int>>();
        counter = 1; // counter need to be "1", because we don't need to calculate distance from parent to itself

        int from, to;
        for(int j = 0; j < V; j++) {
            cin >> from >> to;

            notToVisit[from].insert(to);
            notToVisit[to].insert(from);
            notToVisit[to].insert(to);
            notToVisit[from].insert(from);
        }

        int startEdge;
        cin >> startEdge;
        
        if(startEdge < 1 || startEdge > E)
            continue;
            
        bfs(startEdge);

        for(int j = 1; j < (E + 1); j++) {
            if(j != startEdge)
                cout << distances[j] << " ";
        }
        cout << '\n';
    }
}
