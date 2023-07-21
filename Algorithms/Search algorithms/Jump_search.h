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
