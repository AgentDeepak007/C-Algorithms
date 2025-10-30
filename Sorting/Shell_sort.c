#include <stdio.h>

void shell_sort(int lst[], int n) {
 // shell sort, keeps sorting with gaps that get smaller
 for (int gap = n/2; gap > 0; gap /= 2) {

  // do insertion sort for this gap
  for (int i = gap; i < n; i++) {
   int temp = lst[i];
   int j;

   for (j = i; j >= gap && lst[j - gap] > temp; j -= gap) {
    lst[j] = lst[j - gap];
   }

   lst[j] = temp;
  }

  // one pass done with current gap
 }
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);

 printf("Before: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");

 printf("sorting...\n");

 shell_sort(nums, n);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
