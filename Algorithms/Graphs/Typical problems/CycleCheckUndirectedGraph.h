#pragma once
// Finding cycle in undirected graph using DSUF(Disjoint-set union-find)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int from;
    int to;

    Node() : from(0), to(0) {}
    Node(int from, int to) : from(from), to(to) {}
};

struct RankedNode {
    int parent;
    int rank;

    RankedNode(int parent, int rank) : parent(parent), rank(rank) {}
    RankedNode() : parent(0), rank(0) {}
};

int E, V;
vector<Node> adj;
vector<RankedNode> ranks;

void initializeGraph() {
    adj.clear();
    int from, to;
    int weight; // "weight" is redundant but must be given according to the task...

    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight;
        adj.push_back(Node(from, to));
    }
}
void initializeRanks() {
    ranks.clear();

    for(int i = 0; i <= V; i++) { // If edges' numbers begin from 0 -> then "i < V". Otherwise, "i <= V"
        ranks.push_back(RankedNode(i, 0));
    }
}

void unionEdges(int from, int to) {
    if(ranks[from].rank < ranks[to].rank) {
        ranks[from].parent = to;
    } else if(ranks[to].rank < ranks[from].rank) {
        ranks[to].parent = from;
    } else {
        ranks[from].parent = to;
        ranks[to].rank++;
    }
}
int findParent(int from) {
    if(ranks[from].parent != from) {
        ranks[from].parent = findParent(ranks[from].parent);
    }

    return ranks[from].parent;
}
bool isCyclic() {
    for(int i = 0; i < E; i++) {
        int fromP = findParent(adj[i].from);
        int toP = findParent(adj[i].to);

        if(fromP != toP) {
            unionEdges(fromP, toP);
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    vector<bool> res;

    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++) {
        cin >> V >> E;
        
        if(V == 1) {
            res.push_back(false);
            continue;
        }

        initializeGraph();
        initializeRanks();

        res.push_back(isCyclic());
    }

    for(auto it : res) {
        cout << boolalpha << it << " ";
    }
}

/*

1
3 5
1 3 1
1 2 4
2 3 3
3 1 3
3 2 4
Result: true

1
4 3
3 2 5
3 1 6
1 4 6
Result: false

*/
