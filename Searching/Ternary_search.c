#include <stdio.h>

// ternary search - splits array into 3 parts
int ternary_search(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target)
            return mid1;
        if (arr[mid2] == target)
            return mid2;

        if (target < arr[mid1])
            return ternary_search(arr, left, mid1 - 1, target);
        else if (target > arr[mid2])
            return ternary_search(arr, mid2 + 1, right, target);
        else
            return ternary_search(arr, mid1 + 1, mid2 - 1, target);
    }

    // not found
    return -1;
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

    int res = ternary_search(arr, 0, n - 1, x);
    if (res != -1)
        printf("Found at index %d\n", res);
    else
        printf("Not found :(\n");

    return 0;
}
