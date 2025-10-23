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

// Function declarations
void show_current_state(Stack *backward, Stack *forward);

void init(Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = -1;  // Fixed: should start at -1 for 0-indexed array
    s->data = (Website *)malloc(s->capacity * sizeof(Website));
}

int isEmpty(Stack *s) {
    return s->top == -1;  // Fixed: check against -1
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;  // Fixed: check against capacity-1
}

void push(Stack *s, Website w) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    s->top++;  // Increment first
    s->data[s->top] = w;  // Then assign
}

Website pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop.\n");
        Website empty_site = {"EMPTY", "EMPTY"}; 
        return empty_site;
    }
    Website temp = s->data[s->top];  // Store the value first
    s->top--;  // Then decrement
    return temp;
}

void display(const char *stack_name, Stack *s) {
    printf("--- %s Stack ---\n", stack_name);
    if (isEmpty(s)) {
        printf(" [EMPTY]\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {  // Fixed: go down to 0, not 1
        printf(" %d: %s (%s)\n", i+1, s->data[i].name, s->data[i].url);
    }
}

void function(int n, Stack* backward_stack, Stack* forward_stack) {
    if (n == 1) {  // Go back
        if (!isEmpty(forward_stack)) {
            push(backward_stack, pop(forward_stack));
            show_current_state(backward_stack, forward_stack);
        } else {
            printf("No forward pages available!\n");
        }
    }
    if (n == 2) {  // Go forward
        if (!isEmpty(backward_stack)) {
            push(forward_stack, pop(backward_stack));
            show_current_state(backward_stack, forward_stack);
        } else {
            printf("No backward pages available!\n");
        }
    }
}

void show_current_state(Stack *backward, Stack *forward) {
    if (!isEmpty(backward)) {
        printf("\nCurrent Page: %s\n", backward->data[backward->top].name);
    } else {
        printf("\nCurrent Page: [NONE]\n");
    }
    display("Backward", backward);
    display("Forward", forward);
    printf("\n");
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
    
    for (int i = 0; i < num_sites; i++) {
        push(&backward_stack, sites[i]);
    }

    printf("Initial state:\n");
    show_current_state(&backward_stack, &forward_stack);

    printf("Going forward (moving current page to forward stack):\n");
    int choice = 2;
    function(choice, &backward_stack, &forward_stack);
    
    printf("Going forward again:\n");
    choice = 2;
    function(choice, &backward_stack, &forward_stack);
    
    printf("Going back (moving from forward to backward):\n");
    choice = 1;
    function(choice, &backward_stack, &forward_stack);

    free(backward_stack.data);
    free(forward_stack.data);

    return 0;
}