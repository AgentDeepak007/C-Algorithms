#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int value;
    struct Node *left, *right;
};

// create a new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// insert into bst
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// search in bst
struct Node* search(struct Node* root, int target) {
    if (root == NULL || root->value == target)
        return root;

    if (target < root->value)
        return search(root->left, target);
    else
        return search(root->right, target);
}

int main() {
    int nums[] = {9, 3, 57, 12, 97, 36, 45, 2, 27, 79};
    int n = sizeof(nums) / sizeof(nums[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, nums[i]);

    printf("BST created with values: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    int x;
    printf("Enter number to find: ");
    scanf("%d", &x);

    struct Node* res = search(root, x);
    if (res != NULL)
        printf("Found %d in tree\n", x);
    else
        printf("Not found :(\n");

    return 0;
}
