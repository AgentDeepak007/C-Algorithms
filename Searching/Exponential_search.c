#include <stdio.h>

// binary search helper
int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// exponential search - doubles the range each step
int exponential_search(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;

    // once we pass target, do binary search in range
    if (i > n - 1)
        i = n - 1;

    return binary_search(arr, i / 2, i, target);
}

int main() {
    int arr[] = {2, 3, 9, 12, 27, 36, 45, 57, 79, 97};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Searching in: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter number to find: ");
    scanf("%d", &x);

    int res = exponential_search(arr, n, x);
    if (res != -1)
        printf("Found at index %d\n", res);
    else
        printf("Not found :(\n");

    return 0;
}
