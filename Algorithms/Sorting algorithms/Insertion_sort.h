// Complexity: O(N^2) 
void insertionSort(int* arr, size_t size) 
{
    for (size_t i = 1; i < size; i++)
    {
        int cur = arr[i];
        int prevIdx = i - 1;

        while(prevIdx >= 0 && arr[prevIdx] > cur) 
        {
            arr[prevIdx + 1] = arr[prevIdx];
            prevIdx--;
        }

        arr[prevIdx + 1] = cur;
    }
    
};
