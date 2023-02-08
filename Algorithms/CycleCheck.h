#pragma once
// An approach to find cycle in undirected grapgh using DSU 

#include <bits/stdc++.h>
using namespace std;
 
int v, e;
 
struct Component {
    int parent;
    int rank;
 
    Component() : parent(-1), rank(0) {}
    Component(int parent, int rank) : parent(parent), rank(rank) {}
};
struct Node {
    int from;
    int to;
    int weight;
 
    Node() : from(-1), to(-1), weight(0) {}
    Node(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};
struct Comparator {
    bool operator ()(const Node& f, const Node& s) const {
        return (f.weight > s.weight);
    }
};
 
priority_queue<Node, vector<Node>, Comparator> nodes;
vector<Component> components;
 
void setUpComponents() {
    components = vector<Component>(v);
 
    for(size_t i = 0; i < v; i++) {
        components[i] = Component(i, 0);
    }
}
int find(int val) {
    if(components[val].parent != val) {
        components[val].parent = find(components[val].parent);
    }
 
    return components[val].parent;
}
bool isCyclic() {
    for(size_t i = 0; i < e; i++) {
        Node toOperate = nodes.top();
        nodes.pop();
 
        int root1 = find(toOperate.from);
        int root2 = find(toOperate.to);
 
        if(root1 != root2) {
            if(components[root1].rank < components[root2].rank) {
                components[root1].parent = root2;
            }
            else if(components[root1].rank > components[root2].rank) {
                components[root2].parent = root1;
            }
            else {
                components[root1].parent = root2;
 
                components[root2].rank++;
            }
        }
        else {
            return true;
        }
    }
 
    return false;
}
