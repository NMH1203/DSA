#include<stdio.h>
#include<stdlib.h>

typedef struct _list{
    int *data;
    int size;
    int capacity;  
}list;

list *init(int n){
    list *l=(list*)malloc(sizeof(list));
    l->size=0;
    l->capacity=n;
    l->data=(int *)malloc(l->capacity*sizeof(int));
    return l;
}

int findmax(int a[],int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}

list *findpentagonal(int max, int n, list *l) {
    int temp = (3*n*n - n) / 2;
    if (temp < max) {
        if (l->size >= l->capacity) {
            l->capacity *= 2;
            l->data = realloc(l->data, l->capacity * sizeof(int));
        }
        l->data[l->size] = temp;
        l->size++;
        findpentagonal(max, n+1, l);
    }
    return l;
}

int check(int n,list* a){
    for(int i=0;i<a->size;i++){
        if(n==a->data[i]){
            return 1;
        }
    }
    return 0;
}

void checkarray(int a[], int n, list *l){
    for(int i=0; i<n; i++){  
        if(check(a[i],l)==1){
            printf("Yes\n");  
        }
        else {
            printf("No\n");  
        }
    }
}

int main(){
    int arr[9]={1,4,7,5,12,6,4,8,5};
    list *l=init(10);
    int max=findmax(arr,9);
    list *result=findpentagonal(max,1,l);  
    checkarray(arr,9,result);
    
    free(result->data);
    free(result);
    
    return 0;
}