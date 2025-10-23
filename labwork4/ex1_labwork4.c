#include<stdio.h>
#include<stdlib.h>

// FUNCTION SumDigits(number)
//   SET sum TO 0
//   WHILE number > 0
//     lastDigit = number MOD 10
//     sum = sum + lastDigit
//     number = number / 10
//   END WHILE
//   RETURN sum
// END FUNCTION

// the complexity is O(log(n))

int sum_digit_number(int number){
    int sum=0;                          //1
    while(number>0){                    //log_10(n)
        sum=sum+number%10;              //1
        number=number/10;               //1
    }
    return sum;                         //1
}

//the complexity is O(log(n))

int sum_digit_recursive(int number, int sum){
    if(number<10){                              //1
        return sum+number;                      //1
    }
    else{
        sum=sum+number%10;                      //1 
        number=number/10;                       //1 
        return sum_digit_recursive(number,sum); //log_10(n)
    }   
}



int main(){
    int number=432438;
    printf("%d\n",sum_digit_number(number));
    printf("%d\n",sum_digit_recursive(number,0));
    return 0;
    
}