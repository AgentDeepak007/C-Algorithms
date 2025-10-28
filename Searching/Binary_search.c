#include <stdio.h>

int binary_search(int lst[], int n, int target) {
 // binery search, cuts the list in half each time
 int low = 0;
 int high = n - 1;

 while (low <= high) {
  int mid = (low + high) / 2;
  
  if (lst[mid] == target) {
   return mid;
  } else if (lst[mid] < target) {
    low = mid + 1;
  } else {
   high = mid - 1;
  }
 }

 // not found
 return -1;
}

int main() {
 int nums[] = {2, 3, 9, 12, 27, 36, 45, 57, 79, 97};
 int n = sizeof(nums) / sizeof(nums[0]);
 int x;

 printf("Searching in: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");

 printf("Enter number to find: ");
 scanf("%d", &x);

 int res = binary_search(nums, n, x);

 if (res != -1)
  printf("Found at index %d\n", res);
 else
  printf("Nope, not found :(\n");
}
