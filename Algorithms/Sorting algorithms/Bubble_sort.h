// Time Complexity: O(N^2)
// Stable
void bubbleSort(int* arr, size_t size) 
{
    bool stop = false;
    for (size_t i = 0; i < (size - 1); i++)
    {
        for (size_t j = 0; j < (size - i - 1); j++)
        {
            if(arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
                stop = true;
            }
        }
        if(stop == false) 
            break;
    }
}
