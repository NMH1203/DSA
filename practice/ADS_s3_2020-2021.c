#include <stdlib.h>
#include <stdio.h>

typedef struct _node{
    int data;
    struct _node *pnext;
} Node;

typedef struct _list{
    int size;
    Node *phead;
} List;

void init(List *l){
    l->size=0;
    l->phead=NULL;
}

Node *initNode (int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data=val;
    node->pnext=NULL;
    return node;
}

int isEmpty(List *l){
    return l->size==0;
}

int size(List *l){
    return l->size;
}

void freelist(List *l){
    Node *temp;
    while(l->phead!=NULL){
        temp=l->phead;
        l->phead=l->phead->pnext;
        free(temp);
        l->size--;
    }
}

void add(List *l, int val){
    Node *node =initNode(val);
    if(isEmpty(l)){
        l->phead=node;
    }
    else{
        Node *temp = l->phead;
        while(temp->pnext!=NULL){
            temp=temp->pnext;
        }
        temp->pnext=node;
        
    
    }
    l->size++;
}




int gcd_iterative(int a, int b){
    while(a>b || b>a){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}

void check_iteration(int ar[], int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(gcd_iterative(ar[i],ar[j])==1){
                printf("(%d,%d) ",ar[i],ar[j]);
            }
        }
    }
}

int gcd_recursive(int a, int b){
    if(b==0){
        return a;
    }
    else {
        return gcd_recursive(b,a%b);
    }
}

void check_recursive(int ar[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(gcd_recursive(ar[i],ar[j])==1){
                printf("(%d,%d) ",ar[i],ar[j]);
            }
        }
    }
}

void find(List *l){
    Node *temp;
    if(l->phead == NULL || l->phead->pnext == NULL){
        return;
    }
    Node*ptr1;
    Node *ptr2;
    for(ptr1=l->phead;ptr1!=NULL;ptr1=ptr1->pnext){
        for(ptr2=ptr1->pnext;ptr2!=NULL;ptr2=ptr2->pnext){
            if(gcd_recursive(ptr1->data,ptr2->data)==1){
                printf("(%d,%d) ",ptr1->data,ptr2->data);
            }
        }
    }
}

int main(){
    // int arr[10]={2,10,27,13,90,45,5,26,49,50};
    // check(arr,10);

    List l;
    init(&l);
    add(&l,2);
    add(&l,10);
    add(&l,27);
    add(&l,13);
    add(&l,90);
    add(&l,45);
    add(&l,5);
    add(&l,26);
    add(&l,49);
    add(&l,50);
    find(&l);
    freelist(&l);
    return 0;
}