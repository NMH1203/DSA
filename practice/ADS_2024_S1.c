#include <stdio.h>
#include <stdlib.h>

int reversenumber(int n, int m){
    if(n!=0){
        return reversenumber(n/10,m*10+n%10);
    }
    else return m;
}

int checkpalindromic(int n,int m){
    int sum=n+m;
    // printf("%d",sum);
    int palindromic=reversenumber(sum,0);
    // printf("%d", palindromic);
    if(palindromic==sum){
        return 1;
    }
    return 0;
}


int main(){
    int n=56;
    int reverse=reversenumber(n,0);
    int answer=checkpalindromic(n,reverse);
    if(answer ==1){
        printf("True");
    }
    else printf("False");
    // printf("%d", reverse);
}