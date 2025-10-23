#include<stdio.h>
#include<stdlib.h>


int is_prime(int n){            //n
    if(n<=1){
        return 0;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1; 
}

int is_Sphenic(int n){                  //n^2
    int count = 0;
    for(int i=1;i<=n;i++){                  //n
        if(n%i==0 && is_prime(i)==1){       //n
            count++;
        }
    }
    if(count==3){
        return 1;
    }
    else{
        return 0;   
    }
}

void find_Sphenic(int n){           //n^3
    if(n<1){
        return;
    }
    find_Sphenic(n-1);              //n^2
    if(is_Sphenic(n)==1){
        printf("%d\n",n);
    }
}

int main(){
    find_Sphenic(100);
    return 0;
    //the complexity is O(N^3)
}