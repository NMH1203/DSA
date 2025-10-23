#include<stdio.h>

void findMax(int *max, int a){
    if (a>max){
        max=a;
    }
}

int main(){
    int n;
    int max=-1;
    findMax(&max,n);
    printf("%d", max);
}