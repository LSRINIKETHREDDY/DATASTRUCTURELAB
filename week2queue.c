#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node *next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node *front;
    struct Node *rear;
};

// --- Queue Function Definitions ---
// Function to create an empty queue
struct Queue *create_queue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue *q, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", val);
}

// Function to remove and return the element from the front of the queue
int dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("\nQueue Underflow! Queue is empty.\n");
        q->rear = NULL;
        return -1;
    }
    int val = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return val;
}

// Function to return the front element without removing it
int peek(struct Queue *q) {
    if (q->front == NULL) {
        printf("\nQueue is empty. No element to peek.\n");
        return -1;
    }
    return q->front->data;
}

// Function to display all elements in the queue
void display(struct Queue *q) {
    if (q->front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements (front to rear): ");
    struct Node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// --- Main Program ---
int main() {
    int val, option;
    struct Queue *myQueue = create_queue();

    do {
        printf("\n\n*****QUEUE MENU*****");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(myQueue, val);
                break;
            case 2:
                val = dequeue(myQueue);
                if (val != -1) {
                    printf("\nDequeued value: %d\n", val);
                }
                break;
            case 3:
                val = peek(myQueue);
                if (val != -1) {
                    printf("\nFront element is: %d\n", val);
                }
                break;
            case 4:
                display(myQueue);
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
