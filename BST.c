#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

// void preOrder(struct  node* root){
//     if(root!=NULL){
//         printf("%d ", root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// void postOrder(struct  node* root){
//     if(root!=NULL){
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%d ", root->data);
//     }
// }

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node *insert(struct node *node,int key){
    if(node==NULL){
        return createNode(key);
    }
    else if(key<node->data){
        node->left =insert(node->left,key);
    }
    else if(key>node->data){
        node->right=insert(node->right,key);
    }
    return node;
}
struct node *inprecedoor(struct node *root){
    root=root->left;
    while(root->right!=NULL)
        root=root->right;
    return root;
    
}
struct node *delete_bst(struct node *root,int key){
    struct node *ipre;
    if(root==NULL)
        return NULL;
    if(root->right==NULL && root->left==NULL)
        free(root);
    else if(key>root->data)
        delete_bst(root->right,key);
    else if(key<root->data)
        delete_bst(root->left,key);
    else{
        ipre=inprecedoor(root);
        root->data=ipre->data;
        delete_bst(root->left,ipre->data);
    }
    return root;
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *root=NULL;
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,9);
    printf("inorder\n");
    inOrder(root);
    delete_bst(root,9);
    printf("inorder\n");
    inOrder(root);

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p1->right = p4;

    // struct node* n = search(p, 10);
    // if(n!=NULL){
    // printf("Found: %d", n->data);
    // }
    // else{
    //     printf("Element not found");
    // }
    return 0;
}
