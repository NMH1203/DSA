#include<stdio.h>
#include<stdlib.h>

typedef struct Treenode {
	int val;
	struct Treenode *parent ;
	struct Treenode *tLeft; 
	struct Treenode *tRight;
} *Tree;

Tree* createNode(int val) {
    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1); 
    }
    newNode->val = val;
    newNode->tLeft = NULL;
    newNode->tRight = NULL;
    newNode->parent = NULL;
    return newNode;
}

int main(){
    Tree *myTree = NULL;
    myTree = init(myTree, 5);
    return 0;
}