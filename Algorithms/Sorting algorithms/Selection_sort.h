// Complexity: O(N^2)
void selectionSort(int* arr, size_t size) 
{
    for (size_t i = 0; i < (size - 1); i++)
    {
        for (size_t j = (i + 1); j < size; j++)
        {
            if(arr[i] > arr[j])
                std::swap(arr[j], arr[i]);
        }
    }
};
