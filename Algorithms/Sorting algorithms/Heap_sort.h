// Time complexity: O(nlog(n))
void heapSortAscending(vector<int>& v) {
    for(int i = 0; i < v.size() - 1; i++) {
        make_heap(next(v.begin(), i), v.end(), greater<int>());
    }
}

void heapSortDescending(vector<int>& v) {
    for(int i = 0; i < v.size() - 1; i++) {
        make_heap(next(v.begin(), i), v.end()); // make_heap() makes max_heap by default
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
