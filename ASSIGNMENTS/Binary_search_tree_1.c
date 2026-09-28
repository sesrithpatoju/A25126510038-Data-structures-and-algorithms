#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int id;
    struct Node *left, *right;
};
struct Node* createNode(int val)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->id = val;
    n->left = n->right = NULL;
    return n;
}
struct Node* insert(struct Node* root, int val)
{
    if(root == NULL) 
    return createNode(val);
    if(val < root->id) 
    root->left = insert(root->left, val);
    else if(val > root->id) 
    root->right = insert(root->right, val);
    return root;
}
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->id);
        inorder(root->right);
    }
}
void preorder(struct Node* root)
{
    if(root != NULL) 
    {
        printf("%d ", root->id);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) 
{
    if(root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->id);
    }
}
int search(struct Node* root, int val) 
{
    if(root == NULL) 
    return 0;
    if(root->id == val) 
    return 1;
    if(val < root->id) 
    return search(root->left, val);
    return search(root->right, val);
}
int main() 
{
    struct Node* root = NULL;
    int n, val, key;
    printf("Enter number of identification numbers: ");
    scanf("%d", &n);
    printf("Enter unique IDs:\n");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n\nEnter ID to search: ");
    scanf("%d", &key);
    if(search(root, key)) 
    {
        printf("ID %d exists in the BST.\n", key);
    } 
    else 
    {
        printf("ID %d does not exist in the BST.\n", key);
    }
    printf("\nExplanation: Inorder traversal visits (Left Subtree -> Root -> Right Subtree). Because every node in the left subtree is smaller than root and every node in the right subtree is larger, this recursive ordering outputs all values strictly sorted in ascending order.\n");
    return 0;
}
