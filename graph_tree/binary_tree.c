#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;

Node* initNode(int data, Node* leftchild, Node* rightCilde){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftchild;
    node->rightChild = rightCilde;
    return node;
}

//전위 순회
void preorder(Node* root){
    if (root){
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

//중위 순회
void inorder(Node* root){
    if (root){
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

//후위 순회
void postorder(Node* root){
    if(root){
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ",root->data);
    }
}

void freeAll(Node* root){
    if(root){
        freeAll(root->leftChild);
        freeAll(root->rightChild);
        free(root);
    }
}

int main(void){
    Node *n7 = initNode(50, NULL, NULL);
    Node *n6 = initNode(37, NULL, NULL);
    Node *n5 = initNode(23, NULL, NULL);
    Node *n4 = initNode(5, NULL, NULL);
    Node *n3 = initNode(48, n6, n7);
    Node *n2 = initNode(17, n4, n5);
    Node *n1 = initNode(30, n2, n3);
    preorder(n1);
    printf("\n");
    inorder(n1);
    printf("\n");
    postorder(n1);
    printf("\n");
    freeAll(n1);
    return 0;
}