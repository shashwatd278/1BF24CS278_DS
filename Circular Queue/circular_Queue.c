#include <stdio.h>
#define N 5
int queue[N];
int f = -1;
int R = -1;

void enqueue(int x){
    if (f==-1 && R==-1){
        f=R=0;
        queue[R]=x;
    }
    else if((R+1)%N==f){
        printf("\n Queue is full");
    }
    else{
        R=(R+1)%N;
        queue[R]=x;
    }
}

void dequeue(){
    if (f==-1 && R==-1){
        printf("\n Queue is empty");
    }
    else if (f==R){
        printf("\n Deleted element is %d", queue[f]);
        f=R=-1;
    }
    else{
        printf("\n Deleted element is %d", queue[f]);
        f=(f+1)%N;
    }
}

void display(){
    if (f==-1 && R==-1){
        printf("\n Queue is empty");
    }
    else{
        int i = f;
        while(1){
            printf("\n %d",queue[i]);
            if (i==R){
                break;
            }
            i=(i+1)%N;
        }
        //printf("\n %d",queue[i]);
    }
}

void main(){
    int c;
    printf("\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit");
    printf("\n Enter choice:");
    scanf("%d",&c);
    while (c!=4){
        switch(c){
        case 1:
            {int x;
            printf("\n Enter a number:");
            scanf("%d",&x);
            enqueue(x);
            break;}

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            printf("\n Invalid choice");
            break;
        }
        printf("\n Enter choice:");
        scanf("%d",&c);
    }
    printf("\n Exit!!!!");
}
