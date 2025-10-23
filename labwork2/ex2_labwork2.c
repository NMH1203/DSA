#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int data;
    int capacity;
    char name;
    struct _node *pnext;
} node;

typedef struct _List{
    int size;
    node *phead;
} list;

list* init(){
    list* l=(list*)malloc(sizeof(list));
    l->size=0;
    l->phead=NULL;
    return l;
}

node* initNode(int val, int cap, char na){
    node *newnode=(node *) malloc (sizeof *newnode);
    newnode->data=val;
    newnode->capacity=cap;
    newnode->name=na;
    newnode->pnext=NULL;
    return newnode;
}

int isEmpty (list *l){
    return (l->size==0);
}

void insertFirst(node *pnew, list *ls){
        pnew->pnext = ls->phead;
        ls->size++;
        ls->phead = pnew;
}

void insert (node *pnew , node *ptr, list *l){
    pnew->pnext=ptr->pnext;
    ptr->pnext=pnew;
    l->size++;
}

void removeNode (list *l, int val){
    node*p=l->phead;
    if (l->phead == NULL) { 
        return;
    }
    if(p->data==val){
        l->phead =p->pnext;
        free(p);
        l->size--;
        return;
    }
    node*q=p->pnext;
    while((p->data !=val)&& (p!=NULL)){
        q=p;
        p=p->pnext;
    }
    if(p!=NULL){
        q->pnext=p->pnext;
        free(p);
        l->size--;
        
    }
}


void printList(list *l) {
    if (l->phead == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *current = l->phead;
    printf("Number of cars %d: ", l->size);
    while (current != NULL) {
        printf("[Name: %c, Number passenger: %d] -> ", current->name, current->data);
        current = current->pnext;
    }
    printf("NULL\n");
}

void freeList(list* l) {
    node* current = l->phead;
    node* next_node;
    while(current != NULL) {
        next_node = current->pnext;
        free(current);
        current = next_node;
    }
    free(l);
}

int main(){
    list *l = init();
    
    node* nodeA = initNode(10, 50, 'A');
    insertFirst(nodeA, l);
    
    node* nodeB = initNode(20, 50, 'B');
    insert(nodeB,nodeA, l); 
    
    node* nodeC = initNode(30, 50, 'C');
    insert(nodeC, nodeB, l); 

    node* nodeD = initNode(0, 50, 'D');
    insert(nodeD, nodeB,l); 

    printf("All the railroad cars attached together with name and number of passenger: \n");
    printList(l);
    printf("\n");

    printf("Remove the cars which have 0 passenger \n");
    removeNode(l, 0);
    printList(l);
    printf("\n");
    
    freeList(l);


    return 0;
}
