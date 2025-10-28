#include <stdio.h>

void selection_sort(int lst[], int n) {
 // selection sort, finds the smallest each time and puts it front
 for (int i = 0; i < n; i++) {
  int min_index = i;
  
  for (int j = i + 1; j < n; j++) {
   if (lst[j] < lst[min_index]) {
    min_index = j;
   }
  }

  // swap the found one with current
  int temp = lst[i];
  lst[i] = lst[min_index];
  lst[min_index] = temp;
 
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

 selection_sort(nums, n);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
