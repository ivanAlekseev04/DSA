#pragma once
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: Nlog(N)
void heapSort(vector<int>& v) {
    make_heap(v.begin(), v.end()); // will make max_heap
    // For descending order: make_heap(v.begin(), v.end(), greater<int>());
    auto delim = v.end();

    for(int i = 0; i < v.size(); i++) { // will give ascending order
        pop_heap(v.begin(), delim--);
        // For descending order: pop_heap(v.begin(), delim--, greater<int>());
    }
}
