#include <stdio.h>

void quick_sort(int lst[], int low, int high) {
 // quick sort, picks a pivot and devides stuff around it
 if (low >= high) {
  return;
 }

 int pivot = lst[(low + high) / 2];
 int i = low;
 int j = high;

 while (i <= j) {
  while (lst[i] < pivot)
   i++;
  while (lst[j] > pivot)
   j--;
  if (i <= j) {
   // swap em
   int temp = lst[i];
   lst[i] = lst[j];
   lst[j] = temp;
   i++;
   j--;
  }
 }

 // recurively sort left and right side
 if (low < j)
  quick_sort(lst, low, j);
 if (i < high)
  quick_sort(lst, i, high);
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);

 printf("Before: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
 printf("sorting...\n");

 quick_sort(nums, 0, n - 1);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
