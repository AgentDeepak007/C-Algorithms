#include <stdio.h>

void bubble_sort(int lst[], int n) {
 // bubble sort, keeps swapping untill list is sorted
 
 for (int i = 0; i < n - 1; i++) {
  for (int j = 0; j < n - i - 1; j++) {
   if (lst[j] > lst[j + 1]) {
    // swap em
    int temp = lst[j];
    lst[j] = lst[j + 1];
    lst[j + 1] = temp;
   }
  }
 
  // pass done
  // decrases range each time
 }
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);

 printf("Before: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
 printf("sorting...\n");

 bubble_sort(nums, n);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
