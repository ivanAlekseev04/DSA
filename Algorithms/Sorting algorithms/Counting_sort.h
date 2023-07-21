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
