#pragma once
using namespace std;
#include <list>
#include <unordered_map>

template <class T>
class Graph {
    private:
        unordered_map<T, list<T>> adj;

        void dfsLogic(T vertex, unordered_set<T>& visited) {
            visited.insert(vertex);

            // cout << vertex << " ";

            if (adj.find(vertex) != adj.end()) {
                for (auto v : adj[vertex]) {
                    if (visited.find(v) == visited.end()) {
                        dfsLogic(v, visited);
                    }
                }
            }

            cout << vertex << " "; 
        }
        void dfsTopologicalOrder(T vertex, unordered_set<T>& visited, stack<T>& result) {
            visited.insert(vertex);

            if (adj.find(vertex) != adj.end()) {
                for (auto v : adj[vertex]) {
                    if (visited.find(v) == visited.end()) {
                        dfsTopologicalOrder(v, visited, result);
                    }
                }
            }

            result.push(vertex);
        }
        void bfsLogic(T vertex, unordered_set<T>& visited) {
            visited.insert(vertex);

            queue<int> toVisit;
            toVisit.push(vertex);

            while(!toVisit.empty()) {
                int element = toVisit.front();
                toVisit.pop();

                cout << element << " ";

                for (auto it : adj[element]) {
                    if (visited.find(it) == visited.end()) {
                        toVisit.push(it);
                        visited.insert(it);                        
                    }
                }
            }
        }
    public:

        void addEdge(T vertex, T edge) {
            if (adj.find(vertex) == adj.end()) {
                adj.insert(make_pair(vertex, list<T>()));
            }

            adj[vertex].push_back(edge);
        }

        void dfs(T vertex) {
            if (adj.find(vertex) == adj.end()) {
                return;
            }

            unordered_set<T> visited;

            dfsLogic(vertex, visited);

            for (auto it : adj) {
                if (visited.find(it.first) == visited.end()) {
                    dfsLogic(it.first, visited);
                }
            }  
        }

        void bfs(T vertex) {
            if (adj.find(vertex) == adj.end()) {
                return;
            }
            
            unordered_set<T> visited;
            
            bfsLogic(vertex, visited);

            for (auto it : adj) {
                if (visited.find(it.first) == visited.end()) {
                    bfsLogic(it.first, visited);
                }
            }
        }

        void printTopologicalOrder() {
            if (adj.find(adj.begin()->first) == adj.end()) {
                return;
            }

            T vertex = adj.begin()->first; 

            unordered_set<T> visited;
            stack<T> topologicallyOrdered;

            dfsTopologicalOrder(vertex, visited, topologicallyOrdered);

            for (auto it : adj) {
                if (visited.find(it.first) == visited.end()) {
                    dfsTopologicalOrder(it.first, visited, topologicallyOrdered);
                }
            }
            
            while(!topologicallyOrdered.empty()) {
                cout << topologicallyOrdered.top() << " ";

                topologicallyOrdered.pop();
            }
        }
};