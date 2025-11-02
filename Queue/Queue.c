#include <stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enque(int x){
    if (rear == N-1){
        printf("\nQueue Overflow");
    }
    else if(front == -1 && rear == -1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void deque(){
    if (front ==  -1 && rear ==-1){
        printf("\nQueue is empty");
    }
    else if(front == rear){
        front=rear=-1;
    }
    else{
        printf("\nDeleted is %d", queue[front]);
        front++;
    }
}

void display(){
    if (front ==  -1 && rear ==-1){
        printf("\nQueue is empty");
    }
    for (int i = front; i<=rear; i++){
        printf("%d",queue[i]);
    }
}

void peek(){
    if (front ==  -1 && rear ==-1){
        printf("\nQueue is empty");
    }
    else{
        printf("\nfront is %d",queue[front]);
    }
}

void main(){
    int c;
    printf("1.Enque\n2.Deque\n3.Display\n4.Peek\n5.Exit\n");
    printf("Enter a choice;");
    scanf("%d",&c);
    while (c!=5){
        switch(c){
            case 1:{
                int x;
                printf("\nEnter data:");
                scanf("%d",&x);
                enque(x);
                break;
            }

            case 2:
            deque();
            break;

            case 3:
            display();
            break;

            case 4:
            peek();
            break;

            default:
            printf("\nInvalid choice");
            break;
        }
        printf("\nEnter choice:");
        scanf("%d",&c);
    }
    printf("\nExit !");
}
