#include<stdio.h>
#include<stdlib.h>

int totalnumber(int n){
    int dem=0;          //1
    while(n!=0){        //n
        dem++;         //1 
        n=n/10;         //1
    }
    return dem;
}
// justify 1+2n
// ->complexity O(n);


int power(int n,int m){
    int mul=1;              //1
    for(int i=0;i<m;i++){   //n
        mul=mul*n;          //1
    }
    return mul;            //1 
}
// 1+2n
//->complexity O(n)

void check (int n)
{
    int sum=0;   
    int so=n; 
    while(n!=0){            //n
        int number=n%10;            //1

        n=n/10;                     //1
        sum=sum+power(number,totalnumber(so));     //n^2
    }
    
    if(sum==so){
        printf("Yes");
    }
    else printf("No ");
}
//2+(n*(2+n^2))
//->complexity O(n^3)

//recursion
int totalnumber_r(int n,int m){
    if(n!=0){
        return totalnumber_r(n/10,m+1);
    }
    else return m;
}

int main(){
    int n=153;

    int dem=totalnumber_r(n,0);
    printf("%d",dem);
    //check(n);
}