#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, e, k;

vector<int> al[10000000];

bool visited[10000000];

int currC;
int res;

void dfs(int index)
{
    currC++;
    visited[index] = 1;
    
    for (int i = 0; i < al[index].size(); i++)
    {
        if (visited[al[index][i]] == 0)
        {
            dfs(al[index][i]);
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    
    cin >> n >> e >> k;
    
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        al[x].push_back(y);
        al[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            currC = 0;
            dfs(i);
            
            if (currC % k == 0)
                res++;
        }
    }
    
    cout << res;
    
    return 0;
}
