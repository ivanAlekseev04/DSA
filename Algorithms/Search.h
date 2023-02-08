#pragma once

int binarySearch(const int* arr, size_t left, size_t right, int val) {
    int idxNotFoundElement = -1;

    while(left < right) {
        size_t mid = left + (right - left) / 2;

        if(arr[mid] == val) {
            return mid;
        }
        else if(arr[mid] > val) {
            right = mid;
        }
        else if(arr[mid] < val) {
            left = mid + 1;
        }
    }

    return idxNotFoundElement;
}

int ternarySearch(const int* arr, int left, int right, int val) {
    while(right >= left) {
        int firstMid = left + (right - left) / 3;
        int secondMid = right - (right - left) / 3;

        if(arr[firstMid] == val)
            return firstMid;
        if(arr[secondMid] == val)
            return secondMid;
        
        if(val < arr[firstMid])
            right = firstMid - 1;
        else if(val > arr[secondMid])
            left = secondMid + 1;
        else {
            left = firstMid + 1;
            right = secondMid - 1;
        }
    }

    return -1;
}

int jumpSearch(const int* arr, int left, int right, int val) {
    int toJump = sqrt(right);

    if(val < arr[left] || val > arr[right - 1])
        return -1;

    while(left < right) {
        if(val > arr[left]) {
            if(left + toJump > right - 1) {
                left = right - 1;
                break;
            }
            else
                left += toJump;
        }

        if(val < arr[left])
            break;
    }

    while(left > 0) {
        if(arr[left] == val)
            return left;
        left--;
    }
    
    return -1;
}