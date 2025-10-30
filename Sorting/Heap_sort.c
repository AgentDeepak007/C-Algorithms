#include <stdio.h>

void heapify(int lst[], int n, int i) {
 // makes sure the tree with root i is a heap
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;

 if (left < n && lst[left] > lst[largest])
  largest = left;
 if (right < n && lst[right] > lst[largest])
  largest = right;

 if (largest != i) {
  int temp = lst[i];
  lst[i] = lst[largest];
  lst[largest] = temp;

  heapify(lst, n, largest);
 }
}

void heap_sort(int lst[], int n) {
 // heap sort, turns list into heap then sorts it

 // build max heap
 for (int i = n/2 - 1; i >= 0; i--)
  heapify(lst, n, i);

 // pull elements one by one
 for (int i = n - 1; i > 0; i--) {
  int temp = lst[0];
  lst[0] = lst[i];
  lst[i] = temp;

  heapify(lst, i, 0);
 }
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);

 printf("Before: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");

 printf("sorting...\n");

 heap_sort(nums, n);

 printf("After : ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");
}
