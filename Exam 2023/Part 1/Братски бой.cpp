#include <bits/stdc++.h>
using namespace std;

vector<size_t> first;
vector<size_t> second;
unordered_map<int, int> curDigits;

int main() {
    size_t count;
    cin >> count;

    first = vector<size_t>(count); 
    second = vector<size_t>(count); 

    for(size_t i = 0; i < count; i++) {
        cin >> first[i];
    }

    for(size_t i = 0; i < count; i++) {
        cin >> second[i];
    }

    size_t counter = 0;
    for(size_t i = 0; i < count; i++) {
        curDigits[first[i]]++;

        if(curDigits[second[i]] == 0) {
            counter++;
        } else {
            curDigits[second[i]]--;
        }
    }

    cout << counter << '\n';
}
