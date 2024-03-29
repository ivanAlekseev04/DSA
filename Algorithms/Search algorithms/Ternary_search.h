// Iterative ternary search
int ternarySearch(int* arr, int left, int right, int toFind) { // "right" need to be size - 1
    int notFound = -1;

    while(left <= right) {
        int mid1 = left + ((right - left) / 3);
        int mid2 = right - ((right - left) / 3);

        if(arr[mid1] == toFind) {
            return mid1;
        } else if(arr[mid2] == toFind) {
            return mid2;
        }
        
        if(toFind < arr[mid1]) {
            right = mid1 - 1;
        } else if(toFind > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }  
    }

    return notFound;
}

// Recursive ternary search
int ternarySearch(int* arr, int left, int right, int toFind) {  // "right" need to be size - 1
    int notFound = -1;

    if(left > right) {
        return notFound;
    }

    int mid1 = left + ((right - left) / 3);
    int mid2 = right - ((right - left) / 3);

    if(arr[mid1] == toFind) {
        return mid1;
    } else if(arr[mid2] == toFind) {
        return mid2;
    }
        
    if(toFind < arr[mid1]) {
        ternarySearch(arr, left, mid1 - 1, toFind);
    } else if(toFind > arr[mid2]) {
        ternarySearch(arr, mid2 + 1, right, toFind);
    } else {
        ternarySearch(arr, mid1 + 1, mid2 - 1, toFind);
    }  
}
