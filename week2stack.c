#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node *next;
};

// Stack structure, managed by a top pointer
struct Stack {
    struct Node *top;
};

// --- Stack Function Definitions ---
// Function to create an empty stack
struct Stack *create_stack() {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}

// Function to add an element to the top of the stack
void push(struct Stack *s, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d onto the stack.\n", val);
}

// Function to remove and return the top element from the stack
int pop(struct Stack *s) {
    if (s->top == NULL) {
        printf("\nStack Underflow! Stack is empty.\n");
        return -1; // Sentinel value to indicate an error
    }
    int val = s->top->data;
    struct Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return val;
}

// Function to return the top element without removing it
int peek(struct Stack *s) {
    if (s->top == NULL) {
        printf("\nStack is empty. No element to peek.\n");
        return -1;
    }
    return s->top->data;
}

// Function to display all elements in the stack
void display(struct Stack *s) {
    if (s->top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack elements (top to bottom): ");
    struct Node *current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// --- Main Program ---
int main() {
    int val, option;
    struct Stack *myStack = create_stack();

    do {
        printf("\n\n*****STACK MENU*****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the value to push: ");
                scanf("%d", &val);
                push(myStack, val);
                break;
            case 2:
                val = pop(myStack);
                if (val != -1) {
                    printf("\nPopped value: %d\n", val);
                }
                break;
            case 3:
                val = peek(myStack);
                if (val != -1) {
                    printf("\nTop element is: %d\n", val);
                }
                break;
            case 4:
                display(myStack);
                break;
            case 5:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}
