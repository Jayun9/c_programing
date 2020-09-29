#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b) {
    if (a>b) return a;
    return b;
}

typedef struct Node{
    int data;
    int height;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

int getHeight(Node *node){
    if (node == NULL) return 0;
    return node->height;
}

void setHegiht(Node* node){
    node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDiffenrence(Node *node){
    if (node == NULL) return 0;
    Node* leftChild = node->leftChild;
    Node* rightChild = node->rightChild;
    return getHeight(leftChild) - getHeight(rightChild);
}

//노드에 왼쪽 자식이, 왼쪽 자식에 오른쪽 자식으로,/ 왼쪽 자식에 오른쪽 자식이, 노드로 LL
Node* rotateLL(Node *node){
    Node *leftChild = node->leftChild;
    node->leftChild = leftChild->rightChild;
    leftChild->rightChild = node;
    setHegiht(node);
    return leftChild;
}
//RR ll회전에 반대로 
Node* rotateRR(Node* node){
    Node *rightChild = node->rightChild;
    node->rightChild = rightChild->leftChild;
    rightChild->leftChild = node;
    setHegiht(node);
    return rightChild;
}
//LR회전 RR회전 후 LL회전
Node* rotateLR(Node* node){
    Node *leftChild = node->leftChild;
    node->leftChild = rotateRR(leftChild);
    setHegiht(node->leftChild);
    return rotateLL(node);
}
//RL회전 LR회전에 반대로
Node* rotateRL(Node* node){
    Node *rightChild = node->rightChild;
    node->rightChild = rotateLL(rightChild);
    setHegiht(node->rightChild);
    return rotateRR(node);
}

Node* balance(Node *node){
    int difference = getDiffenrence(node);
    if (difference >= 2){
        if (getDiffenrence(node->leftChild) >= 1){
            node = rotateLL(node);
        }
        else{
            node = rotateLR(node);
        }
    }
    else if (difference <= -2){
        if (getDiffenrence(node->rightChild) <= -1){
            node = rotateRR(node);
        }
        else{
            node = rotateRL(node);
        }
    }
    setHegiht(node);
    return node;
}

Node* insertNode(Node* node, int data){
    if (!node){
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->height = 1;
        node->leftChild = node->rightChild = NULL;
    }
    else if (data < node->data){
        node->leftChild = insertNode(node->leftChild, data);
        node = balance(node);
    }
    else if (data > node->data){
        node->rightChild = insertNode(node->rightChild, data);
        node = balance(node);
    }
    else{
        printf("데이터 중복이 발생했습니다. \n");
    }
    return node;
}
Node* root = NULL;
void display(Node* node, int level){
    if (node!= NULL){
        display(node->rightChild, level +1);
        printf("\n");
        if (node == root){
            printf(" Root : ");
        }
        for (int i = 0; i< level && node != root; i++){
            printf("    ");
        }
        printf("%d(%d)", node->data, getHeight(node));
        display(node->leftChild, level +1);
    }

}

int main(void){
    root = insertNode(root, 7);
    root = insertNode(root, 6);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 9);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 16);
    root = insertNode(root, 23);
    display(root, 1); printf("\n");
    free(root);
    return 0;
}