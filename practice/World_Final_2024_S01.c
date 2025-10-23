#include <stdio.h>
#include <stdlib.h>

int find_min(int n){
    int min=n;
    while (n!=0){
        int end_number=n%10;
        if(end_number<min && end_number!=0){
            min=end_number;
        }
        n=n/10;
    }
    return min;
}

int power(int n){
    if(n!=0){
        return 10*power(n-1);
    }
    else{
        return 1;
    }
}

int create_number(int n, int min){
    int new_number=0;
    int count=0;
    while(n>0){
        if(n%10!=min){
            new_number=(n%10)*power(count)+new_number;
            count++;
        }
        n=n/10;
        
    }
    new_number=power(count)*min+new_number;
    return new_number;
}



int main(){
    int number=51029;
    int min=find_min(number);
    // printf("%d ",min);
    int new_number= create_number(number, min);

    printf("the new number is: %d ", new_number);

}