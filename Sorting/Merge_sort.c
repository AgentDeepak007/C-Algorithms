#include <stdio.h>

void mergeThem(int a[], int a_size, int b[], int b_size, int result[]) {
 int i = 0, j = 0, k = 0;

 // merging part
 while (i < a_size && j < b_size) {
  if (a[i] < b[j]) {
   result[k++] = a[i++];
  } else {
   result[k++] = b[j++];
  }
 }

 // add what’s left from a
 while (i < a_size) {
  result[k++] = a[i++];
 }

  // add what’s left from b (if any)
 while (j < b_size) {
   result[k++] = b[j++];
 }
}

void merge_sort(int lst[], int n) {
 // merge sort, devides the list and then combines in sorted way
 if (n <= 1) return;

 int mid = n / 2;
 int left[mid];
 int right[n - mid];

 for (int i = 0; i < mid; i++) left[i] = lst[i];
 for (int i = mid; i < n; i++) right[i - mid] = lst[i];

 merge_sort(left, mid);
 merge_sort(right, n - mid);

 int result[n];
 mergeThem(left, mid, right, n - mid, result);

 for (int i = 0; i < n; i++) lst[i] = result[i];
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);

 printf("Before: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
 printf("sorting...\n");

 merge_sort(nums, n);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
