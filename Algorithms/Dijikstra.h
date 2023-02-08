#include <bits/stdc++.h>
using namespace std;
 
const int N = 100001;
int dist[N];
vector<pair<int, int>>adjacencyList[N];
 
void shortestPathDijkstra(int v)
{
       for (int i = 0; i < N; i++) {
           dist[i] = INT_MAX;
       }
       
        dist[v] = 0;
 
        priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({ 0,v });
 
        while (!pq.empty()) {
                int current = pq.top().second;
                int costToCurrent = pq.top().first;
                pq.pop();
 
                if(costToCurrent > dist[current]) {
                  continue;
                }
 
                for (pair<int, int> neighbour : adjacencyList[current]) {
                        int child = neighbour.first;
                        int costToChildOfCurrent = neighbour.second;
       
                        if (dist[child] > costToCurrent + costToChildOfCurrent  ) {
                                dist[child] = costToCurrent + costToChildOfCurrent;
                                pq.push({ costToChildOfCurrent + costToCurrent, child });
                        }
                       
                }
        }
 
}
 
int main()
{
        int numberOfEdges = 0, numberOfVertices = 0, costToChildOfCurrent = 0;
        int from = 0, to = 0;
        cin >> numberOfVertices >> numberOfEdges;
        while (numberOfEdges) {
                cin >> from >> to >> costToChildOfCurrent;
         
                adjacencyList[from].push_back({ to, costToChildOfCurrent });
                adjacencyList[to].push_back({ from, costToChildOfCurrent });
         
                numberOfEdges--;
        }
 
        shortestPathDijkstra(0);
 
        for (int i = 0; i < numberOfVertices; i++) {
                cout << dist[i] << " ";
        }
 
        /*
        9 14
        0 1 4
        0 7 8
        1 2 8
        1 7 11
        7 8 7
        7 6 1
        2 8 2
        2 3 7
        2 5 4
        8 6 6
        6 5 2
        5 3 14
        5 4 10
        3 4 9
        */
}
