#pragma once
#include <algorithm>

// Complexity: O(N^2)
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


// Complexity: O(NlogN)
void mergeSort(int* arr, size_t leftStart, size_t rightEnd) 
{
    if(leftStart >= rightEnd)
        return; 

        size_t mid = leftStart + ((rightEnd - leftStart) / 2);

        mergeSort(arr, leftStart, mid);
        mergeSort(arr, mid + 1, rightEnd);
        merge(arr, leftStart, mid, rightEnd);
};

void merge(int* arr, size_t leftStart, size_t mid, size_t rightEnd) 
{
    size_t fSize = mid - leftStart + 1;
    size_t sSize = rightEnd - mid;

    int* fHalf = new int[fSize]{};
    int* sHalf = new int[sSize]{};

    for (size_t i = 0; i < fSize; i++)
        fHalf[i] = arr[leftStart + i];
    
    for (size_t i = 0; i < sSize; i++)
        sHalf[i] = arr[mid + i + 1];
    
    size_t i = 0, j = 0, k = leftStart;
    while(i < fSize && j < sSize)
    {
        if(fHalf[i] >= sHalf[j])
            arr[k++] = sHalf[j++];
        else
            arr[k++] = fHalf[i++];
    }

    while(i < fSize)
        arr[k++] = fHalf[i++];

    while(j < sSize)
        arr[k++] = sHalf[j++];

    delete[] fHalf;
    delete[] sHalf;
}


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

// Complexity: O(n + k)
void countingSort(int* arr, size_t size) 
{
    size_t maxVal = *(std::max_element(arr, arr + size)); 
    int idxs[maxVal + 1]{};

    for(int i = 0; i < size; i++) 
        idxs[arr[i]]++;
    
    for (size_t i = 0, iter = 0; i < maxVal + 1;)
    {
        if(idxs[i] > 0) 
        {
            arr[iter++] = i;
            idxs[i]--;
        }
        else 
            i++;
    }
}

// Counting sort - 2 variant
void countSort(int* arr, int size) {
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

    for(int i = 0; i < size; i++) {
        arr[i] = sorted[i];
    }

    delete buff;
    delete sorted;
}
