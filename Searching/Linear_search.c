#include <stdio.h>

int linear_search(int lst[], int n, int target) {
 // linear search, just checks one by one til found
 for (int i = 0; i < n; i++) {
  if (lst[i] == target) {
   return i;
  }
  
  // keeps going if not found yet
 }
 
 // if we reach here, it isnt  there
 return -1;
}

int main() {
 int nums[] = {9,3,57,12,97,36,45,2,27,79};
 int n = sizeof(nums) / sizeof(nums[0]);
 int x;

 printf("Searching in: ");
 for (int i = 0; i < n; i++) printf("%d ", nums[i]);
 printf("\n");

 printf("Enter number to find: ");
 scanf("%d", &x);

 int res = linear_search(nums, n, x);

 if (res != -1)
  printf("Found at index %d\n", res);
 else
  printf("Not found :(\n");
}
