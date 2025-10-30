#include <stdio.h>
#include <stdlib.h>

void counting_sort(int lst[], int n) {
    // find max value
    int maxVal = lst[0];
    for (int i = 1; i < n; i++) {
        if (lst[i] > maxVal)
            maxVal = lst[i];
    }

    // dynamically allocate count array
    int* count = (int*)calloc(maxVal + 1, sizeof(int));

    // count occurrences
    for (int i = 0; i < n; i++)
        count[lst[i]]++;

    // rebuild sorted array
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            lst[idx++] = i;
            count[i]--;
        }
    }

    free(count); // free memory
}

int main() {
    int nums[] = {9, 3, 57, 12, 97, 36, 45, 2, 27, 79};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Before: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    printf("sorting...\n");

    counting_sort(nums, n);

    printf("After : ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
