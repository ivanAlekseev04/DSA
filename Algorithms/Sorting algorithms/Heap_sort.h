// Time complexity: O(nlog(n))
void heapSortAscending(vector<int>& v) {
    auto iter = v.begin();
    
    for(int i = 0; i < v.size() - 1; i++) {
        make_heap(iter, v.end(), greater<int>());
        iter++;
    }
}

void heapSortDescending(vector<int>& v) {
    auto iter = v.begin();
    
    for(int i = 0; i < v.size() - 1; i++) {
        make_heap(iter, v.end()); // make_heap() makes max_heap by default
        iter++;
    }
}

/*
int main() {
    vector<int> arr =  {12, -12, -1441, 1341, 156, 636, 1, 4, 4, -256, -3};

    heapSortAscending(arr);

    for(auto it : arr) {
        cout << it << " ";
    }
}
*/
