#pragma once
#include <algorithm>

/*More useful sorting algorithms*/

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

    for(int i = 0; i < size; i++) { // Sort in ascending order by default
        arr[i] = sorted[i];         // Fill arr[] in reverse order from sorted[] -> from the end to start
    }

    delete buff;
    delete sorted;
}


/*Less frequent sort algorithms*/

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
