#pragma once

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
vector<Node> mst;
 
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
int kruskal() {
    int minPathWeight = 0;
 
    for(size_t i = 0; i < e; i++) {
        if(mst.size() == v - 1) {
            break;
        }
 
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
 
            minPathWeight += toOperate.weight;
            mst.push_back(toOperate);
        }
    }
 
    return minPathWeight;
}
 
// int main(int argc, char** argv) {
//     cin >> v >> e;
 
//     setUpComponents();
 
//     int from, to, weight;
//     for(size_t i = 0; i < e; i++) {
//         cin >> from >> to >> weight;
 
//         nodes.push(Node(from, to, weight));
//     }
 
//     cout << kruskal() << '\n';
 
//     for(size_t i = 0; i < mst.size(); i++) {
//         cout << mst[i].from << " " << mst[i].to << " " << mst[i].weight << '\n';
//     }
// }