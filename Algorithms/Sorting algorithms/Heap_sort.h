// Time complexity: O(nlog(n))
// Non-stable
void heapSort(int* arr, int size) {
    int rBound = size;

    for(int i = 0; i < (size - 1); i++) {
        make_heap(arr, arr + rBound); // make_heap() function makes max heap
        swap(arr[size - i - 1], arr[0]);
        rBound--;
    }
}

/*
int main() {
    int arr[] =  {12, -12, -1441, 1341, 156, 636, 1, 4, 4, -256, -3};
    int size = (sizeof(arr) / sizeof(arr[0]));

    heapSort(arr, size);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
*/
