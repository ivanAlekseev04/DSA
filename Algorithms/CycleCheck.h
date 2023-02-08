#pragma once
// Finding cycle in undirected graph using DSU

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
 
    Node() : from(-1), to(-1) {}
    Node(int from, int to) : from(from), to(to) {}
};
 
vector<Node> graph;
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
        Node toOperate = graph[i];
 
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

// int main(int argc, char** argv) {
//     cin >> v >> e;

//     setUpComponents();

//     for(int i = 0, from = 0, to = 0; i < e; i++) {
//         cin >> from >> to;

//         graph.push_back(Node(from, to));
//     }

//     cout << boolalpha << isCyclic() << '\n';

//     /*
//     5 4
//     1 3
//     3 0
//     0 2
//     2 4
//     Result: false

//     5 5
//     1 3
//     3 0
//     0 2
//     2 4
//     4 0
//     Result: true
//     */
// }
