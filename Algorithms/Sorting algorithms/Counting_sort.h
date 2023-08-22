// Complexity: O(n + k)
// Stable
void countingSort(int* arr, int size) { 
    int max = *max_element(arr, arr + size);

    int* buff = new int[max + 1]{};

    for(int i = 0; i < size; i++) {
        buff[arr[i]]++;
    }

    for(int i = 1; i < max + 1; i++) {
        buff[i] += buff[i - 1];
    }

    int* sorted = new int[size]{};

    for(int i = size - 1; i >= 0; i--) {
        sorted[buff[arr[i]] - 1] = arr[i];
        buff[arr[i]]--;
    }

    for(int i = 0; i < size; i++) { // Sort in ascending order by default
        arr[i] = sorted[i];         // Fill arr[] in reverse order from sorted[] -> from the end to start
    }

    delete buff;
    delete sorted;
}

// Counting sort + removing duplicates
void countingSort(vector<int>& v) {
    int maxVal = *max_element(v.begin(), v.end());
    vector<int> idxs(maxVal + 1);
    
    int newSize = v.size();

    for(auto it : v) {
        if(idxs[it] == 1) {
            newSize--;
        } else {
            idxs[it]++;
        }
    }

    for(int i = 1; i < idxs.size(); i++) {
        idxs[i] += idxs[i - 1];
    }

    vector<int> res(newSize);

    for(int i = v.size() - 1, j = 0; j < newSize; i--) {
        if(idxs[v[i]] == 0) {
            continue;
        } else {
            j++;
        }

        res[idxs[v[i]] - 1] = v[i];
        idxs[v[i]] = 0;
    }

    v = res;
}
