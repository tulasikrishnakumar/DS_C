#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->key=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void InorderTraversal(struct Node *root){
    if(root==NULL)
        return;
    InorderTraversal(root->left);
    printf("%d ",root->key);
    InorderTraversal(root->right);
}
void PreorderTraversal(struct Node *root){
    if(root==NULL)
        return;
    printf("%d ",root->key);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void PostorderTraversal(struct Node *root){
    if(root==NULL)
        return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d ",root->key);
}

int main(){
    struct Node* root=newNode(10);
    root->left=newNode(26);
    root->right=newNode(53);
    root->left->left=newNode(94);
    root->right->right=newNode(45);
    printf("Inorder traversal: \n");
    InorderTraversal(root);
    printf("\nPost order Traversal: \n");
    PostorderTraversal(root);
    printf("\npreorder traversal: \n");
    PreorderTraversal(root);
    return 0;
}