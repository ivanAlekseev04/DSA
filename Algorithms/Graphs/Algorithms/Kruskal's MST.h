#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int from;
    int to;
    int weight;

    Node() : from(0), to(0), weight(0) {}
    Node(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

struct RankedNode {
    int parent;
    int rank;

    RankedNode() : parent(0), rank(0) {}
    RankedNode(int parent, int rank) : parent(parent), rank(rank) {}
};

int E, V;
vector<Node> adj;
vector<RankedNode> ranks;

// For the result
vector<Node> mst;
int MSTcost = 0;

// Preparation/initialization
void initializeRanks() {
    for(int i = 0; i < V; i++) {
        ranks.push_back(RankedNode(i, 0));
    }
}
void initializeEdges() {
    int from, to, weight;

    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight;
        adj.push_back(Node(from, to, weight));
    }
}

// Initial functions for the Kruskal's MST
int findParent(int from) {
    if(ranks[from].parent != from) { // Diging down to the parents of "from" till there is no parents of the "from"
        ranks[from].parent = findParent(ranks[from].parent); // Path-compression technique; works similarly to remove/insert in BST
    }

    return ranks[from].parent;
}
void unionEdges(int from, int to) {
    if(ranks[from].rank < ranks[to].rank) {
        ranks[from].parent = to;
    } else if(ranks[from].rank > ranks[to].rank) {
        ranks[to].parent = from;
    } else {
        ranks[from].parent = to;
        ranks[to].rank++;
    }
}
bool kruskal() {
    sort(adj.begin(), adj.end(), [](Node& f, Node& s) {return f.weight < s.weight;}); // Sorting edges in increasing order by "weight"

    int i = 0, j = 0;

    while(i < V - 1 && j < E) {
        int fromP = findParent(adj[j].from);
        int toP = findParent(adj[j].to);
        int weight = adj[j].weight;

        j++; // Iterator for the edges in graph

        if(fromP == toP) {
            continue;
        }

        unionEdges(fromP, toP);
        MSTcost += weight;
        mst.push_back(adj[j - 1]);

        i++; // Incrementing count of edges already existed in MST 
    }

    if(i != V - 1) // Final check, whether MST was formed completely
        return false;

    return true; 
}   

int main() {
    cin >> V >> E;

    initializeRanks();
    initializeEdges();

    if(!kruskal()) {
        cout << "MST can't be formed for this graph\n";
        return -1;
    }

    cout << "\nMST cost is: " << MSTcost << '\n';
    for(auto it : mst) {
        cout << "From: " << it.from << " To: " << it.to << " Weight: " << it.weight << '\n';
    }

    return 0;
}
