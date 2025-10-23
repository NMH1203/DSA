#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[100];
    int quantity;
    int price_in_stock;
}product;

typedef struct {
    char name[100];
    int number_product_want_to_buy;
    char name_product[100];
}customers;

typedef struct _Queue {
    int front , back;
    int capacity;
    int size;
    customers *val;
}Queue;

void init (Queue *q, int N){
    q->back=0;
    q->front=0;
    q->capacity=N;
    q->val=(customers*)malloc(q->capacity*sizeof(customers));

}
int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

int enqueue_customers(Queue *q, customers cust){
    int l = q->back-q->front;
    if(isFull(q)){
        return 0;
    }
    q->val[q->back]=cust;
    q->back++;
    q->size++;
    return 1;
}

customers dequeue(Queue*q){
    customers empty_cust= {0};

    if(q->back==0){
        return empty_cust;
    }
    customers front_cust = q->val[q->front];
    q->front++;
    q->size--;

    return front_cust;
}

int freeQueue(Queue *q){
    free(q->val);
}

int main(){
    Queue newQueue;
    int number_capacity =10;
    init(&newQueue,number_capacity);

    product items[3]={
        {"item1",10,3},
        {"item2",34,7},
        {"item2",3,43}
    };

    int num_products = sizeof(items) / sizeof(items[0]);

    customers all_customers[5]={
        {"customer1",3,"item1"},
        {"customer2",5,"item2"},
        {"customer3",8,"item1"},
        {"customer4",6,"item3"},
        {"customer5",2,"item1"},
    };

    int num_customers = sizeof(all_customers) / sizeof(all_customers[0]);

    while(!isEmpty(&newQueue)){
        customers curr= dequeue(&newQueue);
        int f=0;
        for(int i=0;i<num_customers;i++){
            if(items[i].name==curr.name_product){
                f=1;
                if(items[i].quantity>=curr.number_product_want_to_buy){
                    printf("%c purchase successful %d %c ",curr.name,curr.number_product_want_to_buy,curr.name_product);
                    items[i].quantity=-curr.number_product_want_to_buy;
                } else  {
                    printf("%c not enough for  %c",curr.name_product,curr.name);
                }             
            }
        }
    }
    freeQueue(&newQueue);
}