// Iterative binary search
int binarySearch(int* arr, int left, int right, int toFind) { // "right" need to be size - 1
    int notFound = -1;

    while(left <= right) {
        int mid = left + ((right - left) / 2);

        if(arr[mid] == toFind) {
            return mid;
        } else if(arr[mid] > toFind) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }   
    }

    return notFound;
}

//Recursive binary search
int binarySearch(int* arr, int left, int right, int toFind) { // "right" need to be size - 1
    if(left > right) {
        return -1;
    }

    int mid = left + ((right - left) / 2);

    if(arr[mid] == toFind) {
        return mid;
    } else if(arr[mid] > toFind) {
        binarySearch(arr, left, mid - 1, toFind);
    } else {
        binarySearch(arr, mid + 1, right, toFind);
    }
}
