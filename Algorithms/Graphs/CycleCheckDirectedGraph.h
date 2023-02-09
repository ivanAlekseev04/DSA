#pragma once

#include <bits/stdc++.h>
using namespace std;

bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr) {
    if(visited[curr]) {
        return true;
    }
    
    visited[curr] = true;
    bool FLAG = false;
  
    for(int i = 0; i < adj[curr].size(); ++i) {
        FLAG = isCyclic_util(adj, visited, adj[curr][i]);
      
        if(FLAG) {
            return true;
        }
    }
  
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
   vector<bool> visited(V, false);
   bool FLAG = false;
  
   for(int i = 0; i < V; ++i) {
           visited[i] = true;
     
           for(int j = 0; j < adj[i].size(); ++j) {
               FLAG = isCyclic_util(adj,visited,adj[i][j]);
             
               if(FLAG) {
                   return true;
               }
           }
     
           visited[i] = false;
   }
  
   return false;
}

// int main() {
	
// 	int t;
// 	cin >> t;
	
// 	while(t--){
	    
// 	    int v, e;
// 	    cin >> v >> e;
	    
// 	    vector<int> adj[v];
	    
// 	    for(int i =0;i<e;i++){
// 	        int u, v;
// 	        cin >> u >> v;
// 	        adj[u].push_back(v);
// 	    }
	    
// 	    cout << isCyclic(v, adj) << endl;
	    
// 	}
// }


// Second approach (easier)
// https://www.hackerrank.com/contests/sda-exam-27-01-19-/challenges/-1-12

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void dfs(int start, int vertex, bool& isCycle, vector<bool>& visited) {
    visited[vertex] = true;
    
    for(auto v : adj[vertex]) {
        if(start == v) {
            isCycle = true;
        }
        
        if(!visited[v]) {
            dfs(start, v, isCycle, visited);
        }
    }
}

// int main() {
//     int tests;
    
//     cin >> tests;
    
//     for(int i = 0; i < tests; i++) {
//         int v, e;
        
//         cin >> v >> e;
        
//         adj = vector<vector<int>>(v + 1);
        
//         for(int j = 0; j < e; j++) {
//             int from, to, weight;
            
//             cin >> from >> to >> weight;
            
//             adj[from].push_back(to);
//         }

//         bool isCycle = false;
        
//         for(int j = 1; j < v + 1; j++) {
//             vector<bool> visited(v + 1);
            
//             dfs(j, j, isCycle, visited);
            
//             if(isCycle) {
//                 cout << "true" << " ";
                
//                 break;
//             }
//         }
        
//         if(!isCycle) {
//             cout << "false" << " ";
//         }
//     }
// }
