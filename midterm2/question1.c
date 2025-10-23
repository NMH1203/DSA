#include <stdio.h>

int decimal_interger(int a){
    int size=0;
    int decimal[100];
    while(a>0){
        decimal[size]=a%2;
        a=a/2;
        size=size+1;
    }
    int number=0;
    for(int i=size-1;i>=0;i--){
        number=number*10+decimal[i];
    }
    return number;
}

int power(int n){
    int a=1;
    for(int i=0;i<=n;i++){
        a=a*10;
    }
    return a;
}

float decimal_fraction(float a,int k){
    int decimal[100];
    
    for(int i=0;i<k;i++){
        a=a*2;
        if(a>=1){
            decimal[i]=1;
            a=a-1;
        }
        else{
            decimal[i]=0;
        }
    }

    float number=0;
    for(int i=k-1;i>=0;i--){
        number=(number+decimal[i])/10;
    }
    return number;
}

int main(){
    float a=4.47;
    int intergerpart= a;
    // printf("%d\n",intergerpart);
    float decimalpart=a-intergerpart;
    float decimal_number= decimal_interger(intergerpart)+decimal_fraction(decimalpart,5);
    printf("%.f",decimal_number);
    return 0;
}