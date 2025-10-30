#include <stdio.h>

void insertion_sort(int lst[], int n) {
 // insertion sort, picks one element and puts it in right place
 for (int i = 1; i < n; i++) {
  int key = lst[i];
  int j = i - 1;

  // move stuff bigger than key one step ahead
  while (j >= 0 && lst[j] > key) {
   lst[j + 1] = lst[j];
   j--;
  }

  lst[j + 1] = key;

  // one pass done, moves on
 }
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);

 printf("Before: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");

 printf("sorting...\n");

 insertion_sort(nums, n);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
