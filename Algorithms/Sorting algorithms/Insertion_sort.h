// Complexity: O(N^2) 
void insertionSort(vector<int>& v) {
    for(int i = 1; i < v.size(); i++) {
        for(int j = i; j >= 1; j--) {
            if(v[j - 1] > v[j]) {
                swap(v[j - 1], v[j]);
            } else {
                break;
            }
        } 
    }
};
