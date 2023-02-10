#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
int stickers[5000000];
int wanted[5000000];

map<int, int> s;

int f;

int main() {
    ios::sync_with_stdio(false); 
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> stickers[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> wanted[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        s[stickers[i]]++;
        
        if (s[wanted[i]] == 0)
        {
            f++;
        }
        else
        {
            s[wanted[i]]--;
        }
    }
    
    cout << f << endl;
    
    return 0;
}
