#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[100];
    char url[100];
} Website;


typedef struct {
    int top;      
    int capacity; 
    Website *data;
} Stack;


void init(Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = 0; 
    s->data = (Website *)malloc(s->capacity * sizeof(Website));
}


int isEmpty(Stack *s) {
    return s->top == 0;
}


int isFull(Stack *s) {
    return s->top == s->capacity;
}

void push(Stack *s, Website w) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    s->top++; 
    s->data[s->top] = w;
}


Website pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop.\n");
        Website empty_site = {"EMPTY", "EMPTY"}; 
        return empty_site;
    }
    Website temp = s->data[s->top];  
    s->top--;  
    return temp;
}


void display(const char *stack_name, Stack *s) {
    printf("--- %s Stack ---\n", stack_name);
    if (isEmpty(s)) {
        printf(" [EMPTY]\n");
        return;
    }
    for (int i = s->top; i > 0; i--) {
        printf(" %d: %s (%s)\n", i, s->data[i].name, s->data[i].url);
    }
}

void show_current_state(Stack *backward, Stack *forward) {
    if(!isEmpty(backward)) {
        printf("\n Current Page: %s\n", backward->data[backward->top].name);
    } else {
        printf("\n Current Page: [NONE]\n");
    }
    display("Backward", backward);
    display("Forward", forward);
}

void function(int n,Stack* backward_stack, Stack* forward_stack){
    if(n==1){
        push(backward_stack, pop(forward_stack));
        show_current_state(&backward_stack, &forward_stack);
    }
    if(n==2){
        push(forward_stack, pop(backward_stack));
        show_current_state(&backward_stack, &forward_stack);
    }
}


int main() {
    Stack backward_stack;
    Stack forward_stack;

    init(&backward_stack, 10);
    init(&forward_stack, 10);

    Website sites[] = {
        {"Google", "google.com"},
        {"Facebook", "facebook.com"},
        {"GitHub", "github.com"},
        {"StackOverflow", "stackoverflow.com"}
    };
    int num_sites = sizeof(sites) / sizeof(sites[0]);
    for(int i = 0; i < num_sites; i++) {
        push(&backward_stack, sites[i]);
    }

    display("Backward", &backward_stack);
    display("Forward", &forward_stack);

    int choice=2;
    function(choice,&backward_stack,&forward_stack);
    choice=2;
    function(choice,&backward_stack,&forward_stack);
    choice=1;
    function(choice,&backward_stack,&forward_stack);



    
    free(backward_stack.data);
    free(forward_stack.data);

    return 0;
}