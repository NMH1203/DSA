#include<stdio.h>

int decimal_integer_recursive(int a){
    if(a==0){
        return 0;
    }
    else return a%2+10*decimal_integer_recursive(a/2);
}

float decimal_fraction_recursive(float a, int k){
    if(k==0){
        return 0;
    }
    else{
        a=a*2;
        if(a>=1){
            return (1+decimal_fraction_recursive(a-1,k-1))/10;
        }
        else{
            return (0+decimal_fraction_recursive(a,k-1))/10;
        }
    }
}

int main(){
    float a=4.47;
    int intergerpart=a;
    float decimalpart=a-intergerpart;
    printf("%d",decimal_integer_recursive(intergerpart));
    printf(".%f \n",decimal_fraction_recursive(decimalpart,5));
    float decimal_number= (float)decimal_integer_recursive(intergerpart)+decimal_fraction_recursive(decimalpart,5);
    printf("%f",decimal_number);
    return 0;
}
