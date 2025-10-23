#include<stdio.h>
#include<stdlib.h>

int check(int a , int b, int c){
    if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a){
        return 1;
    }
    return 0;
} //-> O(1)

void recursiveway(int a[], int n,int b, int c, int d){
    if(d<n){
        if(check(a[b],a[c],a[d])){
            printf("%d %d %d\n",a[b],a[c],a[d]);
        }
        recursiveway(a,n,b,c,d+1);  //->n
    }
    else if(c<n-1){
        recursiveway(a,n,b,c+1,c+2); //->n
    }
    else if(b<n-2){
        recursiveway(a,n,b+1,b+2,b+3); //->n
    }  
} //-> O(n^3)

int main(){
    int arr[]={3, 12, 5, 5, 4, 10, 6, 13};
    int size=sizeof(arr)/sizeof(arr[0]);

    recursiveway(arr,size,0,1,2);
}