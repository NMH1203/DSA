#include<stdio.h>

struct number
{
    int real;
    int fake;
};

struct number add (struct number c1 , struct number c2){
    struct number result;
    result.real = c1.real + c2.real;
    result.fake = c1.fake + c2.fake;

    return result;
}

struct number multi (struct number c1 , struct number c2){
    struct number result;
    result.real = c1.real * c2.real- c1.fake * c2.fake; //(ac - bd)
    result.fake = c1.real*c2.fake + c2.real * c1.fake; //(ad + bc)
    return result;
}

void print(struct number c){
    if (c.fake >= 0){
        printf("%d + %di", c.real, c.fake);
    } else {
        printf("%d - %di", c.real, -c.fake);
    }
}

int main(){
    struct number c1, c2, sum, product;

    printf("Enter real and imaginary part of first complex number: ");
    scanf("%d %d", &c1.real, &c1.fake);
    printf("Enter real and imaginary part of second complex number: ");
    scanf("%d %d", &c2.real, &c2.fake);

    sum = add(c1, c2);
    product = multi(c1, c2);

    printf("Sum: ");
    print(sum);
    printf("\nProduct: ");
    print(product);
    
    return 0;
}





