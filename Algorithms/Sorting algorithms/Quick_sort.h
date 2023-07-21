// Complexity: O(NlogN)
void quickSort(int* arr, int low, int high) 
{
    if(low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
};
size_t partition(int* arr, size_t low, size_t high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if(arr[j] < pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
        std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
