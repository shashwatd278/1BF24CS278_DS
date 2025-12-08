#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int n) {
    int data;
    for (int i=1; i<=n;i++){
        printf("Enter data:");
        scanf("%d",&data);
        struct Node* newNode = createNode(data);
        newNode->next = *top;
        *top = newNode;
    }
    printf("pushed\n");
}

void pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = *top;
    printf("popped\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

void displayStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void enqueue(struct Node **front, struct Node **rear, int n) {
    int data;
    for (int i=1; i<=n;i++){
        printf("Enter data:");
        scanf("%d",&data);
        struct Node* newNode = createNode(data);
        if (*rear == NULL) {
            *front = *rear = newNode;
        } else {
            (*rear)->next = newNode;
            *rear = newNode;
        }
    }

    printf("enqueued\n");
}

void dequeue(struct Node **front, struct Node **rear) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = *front;
    printf("%dequeued\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void displayQueue(struct Node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    struct Node *stackTop = NULL;
    struct Node *queueFront = NULL, *queueRear = NULL;
    int choice, n;

    printf("1. Push (Stack)\n");
    printf("2. Pop (Stack)\n");
    printf("3. Display Stack\n");
    printf("4. Enqueue (Queue)\n");
    printf("5. Dequeue (Queue)\n");
    printf("6. Display Queue\n");
    printf("7. Exit\n");


    while (1) {

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter length of stack: ");
                scanf("%d", &n);
                push(&stackTop, n);
                break;
            case 2:
                pop(&stackTop);
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                printf("Enter length of queue: ");
                scanf("%d", &n);
                enqueue(&queueFront, &queueRear, n);
                break;
            case 5:
                dequeue(&queueFront, &queueRear);
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
