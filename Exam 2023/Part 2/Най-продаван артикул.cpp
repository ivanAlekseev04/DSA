#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int, pair<long long, int> > pii;
int n;
int t;

priority_queue<pii, vector<pii> > pq;
int c[500000];

pair<int, long long> p[100001];
vector<pair<long long,int> > times;
int k;
pii pt;

int getProduct(int q)
{
    int left = 0;
    int right = k-1;
    int mid = (left + right) / 2;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (times[mid].first <= q && times[mid + 1].first > q)
        {
            return times[mid].second;
        }
        if (times[mid].first > q)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return times[mid].second;
}
int main() {
    ios::sync_with_stdio(false);
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first;
        cin >> p[i].second;
        
        c[p[i].first]++;
        
        pq.push(make_pair(c[p[i].first], make_pair(p[i].second, p[i].first)));
        pt = pq.top();
        //cout << pt.first << " " << pt.second.first << " " << pt.second.second << endl;
        times.push_back(make_pair(pt.second.first, pt.second.second));
    }
    
    cin >> t;
    k = times.size();
    times.push_back(make_pair(10000000000, -1));
    int last;
    int q;
    for (int i = 0; i < t; i++)
    {
        cin >> q;
        if (q < times[0].first)
        {
            cout << "-1\n";
        }
        else
        {
            cout << getProduct(q) << "\n";
        }
    }
    
    return 0;
}
