#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
typedef pair<int, pair<int, int> > piii;
int n;
int t;
priority_queue<piii, vector<piii>, greater<piii> > in;
priority_queue<piii, vector<piii>, greater<piii> > out;
priority_queue<int, vector<int>, greater<int>> fs;

bool isFree[500001];
int seated[500001];

int main() {
    
    ios::sync_with_stdio(false);
    
    cin >> n;
    int x, y;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        
        in.push(make_pair(x, make_pair(y, i)));
        out.push(make_pair(y, make_pair(x, i)));
        fs.push(i);
    }
    
    cin >> t;
    
    for (int i = 0; i < n; i ++)
    {
        piii curr = in.top();
        in.pop();
        
        int time = curr.first;
        
        if (!out.empty())
        {
            piii currO = out.top();

            while (currO.first <= time)
            {
                fs.push(seated[currO.second.second]);
                out.pop();
                if (out.empty())
                {
                     break;
                }
                else
                {
                    currO = out.top();
                }
            }
        }
        
        seated[curr.second.second] = fs.top();
        fs.pop();
        
        if (curr.second.second == t)
        {
            cout << seated[t];
            return 0;
        }
    }
    
    return 0;
}
