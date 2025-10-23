#include <stdio.h>
#include <stdlib.h>

typedef struct _List {
    int sign;
    int size;
    int capacity;
    int *val;
} list;

list* initList(int N){
    list* l=(list*)malloc(sizeof(list));
    l->size=0;
    l->capacity=N;
    l->val=(int*)malloc(l->capacity*sizeof(int));
    return l;
}

void display(list*l, int a){
    if(a==-1){
        printf("List: -");
    }
    else{
        printf("List: ");
    }
    for(int i=0;i<l->size;i++){
        printf("%d",l->val[i]);
    }
    printf("\n");
}

void add(list*l,int val,int index){
    for(int i=l->size;i>index;i--){
        l->val[i]=l->val[i-1];
    }
    l->val[index]=val;
    l->size++;
}

void remove(list*l,int index){
    for(int i=index;i<l->size-1;i++){
        l->val[i]=l->val[i+1];
    }
    l->size--;
}

int sum(list*l){
    int s=0;
    for(int i=0;i<l->size;i++){
        s+=l->val[i];
    }
    return s;
}






int main () {
    list* mylist=initList(100);
    int a=-1;
    add(mylist, 345, 0);
    add(mylist, 9237, 1);
    add(mylist, 2857, 2);
    add(mylist, 123, 3);
    add(mylist, 456, 4);

    printf("the list is: ");
    for(int i=0;i<mylist->size;i++){
        printf("%d ",mylist->val[i]);
    }

    printf("\n");
    printf("after the insert the list is: ");
    add(mylist, 999, 2);
    for(int i=0;i<mylist->size;i++){
        printf("%d ",mylist->val[i]);
    }

    printf("\n");
    printf("after the remove the list is: ");
    remove(mylist, 4);
    for(int i=0;i<mylist->size;i++){
        printf("%d ",mylist->val[i]);
    }

    printf("\n");
    printf("the sum of the list is: %d\n", sum(mylist));

    printf("the whole number is: ");
    display(mylist, a);
    

    free(mylist->val);
    free(mylist);
    return 0;
}