#include<stdio.h>
#include<stdbool.h>

bool check_prime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

void spheric_number(int n, int a[]){
    int dem=0;
    for(int i=1; i<=n;i++){
        if (n%i==0){
            dem++;
            a[dem-1]=i;
        }
    }
    if(dem==8){
        int dem1=0;
        for(int i=0; i<dem; i++){
            if(check_prime(a[i])==true){
                dem1++;
            }
        }
        if(dem1==3){
            printf("yes");
        }
        else{
            printf("NO");
        }
    }
    else {
        printf("NO");   
    }
}

int main(){
    int n;
    int a[8];
    scanf("%d", &n);
    spheric_number(n,a);
}