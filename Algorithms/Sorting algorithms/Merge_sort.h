// Complexity: O(NlogN)
void mergeSort(int* arr, int start, int end) { // "End" need to be (size - 1) for the proper work
    if (start < end) {
        int mid = start + ((end - start) / 2);

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}; 

void merge(int* arr, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for(int i = 0; i < leftSize; i++) {
        left[i] = arr[start + i];
    }

    for(int i = 0; i < rightSize; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int leftIdx = 0;
    int rightIdx = 0;
    int mergeIdx = start;

    while(leftIdx < leftSize && rightIdx < rightSize) {
        if(left[leftIdx] <= right[rightIdx]) { // ">=" gives descending order; "<=" gives ascending order
            arr[mergeIdx++] = left[leftIdx++];
        } else {
            arr[mergeIdx++] = right[rightIdx++];
        }
    }

    while(leftIdx < leftSize) {
        arr[mergeIdx++] = left[leftIdx++];
    }

    while(rightIdx < rightSize) {
        arr[mergeIdx++] = right[rightIdx++];
    }

    delete left;
    delete right; 
}
