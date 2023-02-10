#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m;
int p;

int k;

pii r[1000001];
int a[1001];

bool b[1001];
bool av[1001];

vector<int> al[1001];

int currQ;
int visited[1001];

int bfs(int start, int end)
{
    queue<pii> q;
    visited[start] = currQ;
    q.push(make_pair(start, 0));
    
    while(!q.empty())
    {
        pii curr = q.front();
        
        for (int i = 0; i < al[curr.first].size(); i++)
        {
            if (al[curr.first][i] == end)
                return curr.second + 1;
            
            if (visited[al[curr.first][i]] < currQ && av[al[curr.first][i]] == 0)
            {
                q.push(make_pair(al[curr.first][i], curr.second+1));
                visited[al[curr.first][i]] = currQ;
            }
            
        }
        q.pop();
    }
    
    return -1; 
}

int main() {
    
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> r[i].first >> r[i].second;
    }
    
    cin >> p;
    
    for (int i = 0; i < p; i++)
    {
        cin >> a[i];
        av[a[i]] = 1;
    }
    
    cin >> k;
    
    int x;
    for (int i = 0; i < k ; i++)
    {
        cin >> x;
        
        b[x] = true;
    }
    
    for (int i = 0; i < m; i++)
    {
        if (b[r[i].first] == 0 && b[r[i].second] == 0)
        {
            al[r[i].first].push_back(r[i].second);
            al[r[i].second].push_back(r[i].first);
        }
    }
    
    currQ = 1;
    int res = 0;
    for (int i = 1; i < p; i++)
    {
        av[a[i-1]] = 0;
        av[a[i]] = 0;
        
        int l = bfs(a[i-1], a[i]);
        
        if (l == -1)
        {
            cout << "-1\n";
            return 0;
        }
        else
        {
            res += l;
        }
        
        currQ ++;
    }
    
    cout << res;
    
    return 0;
}
