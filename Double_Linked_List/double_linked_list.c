#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

void create(int n){
    struct Node *NewNode;
    int data;
    for(int i=1;i<=n;i++){
        NewNode=(struct Node*)malloc(sizeof(struct Node));
        NewNode->prev=NewNode->next=NULL;
        printf("\nEnter data:");
        scanf("%d",&data);
        NewNode->data=data;
        if(head==NULL){
            head=tail=NewNode;
        }
        else{
            tail->next=NewNode;
            NewNode->prev=tail;
            tail=NewNode;
        }
    }
}

void insertfirst(int data){
   struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
   NewNode->prev=NULL;
   NewNode->next=head;
   NewNode->data=data;
   if(head==NULL){
    head=tail=NewNode;
    return;
   }
   head->prev=NewNode;
   head=NewNode;
   printf("\nInserted at first!");
}

void insertend(int data){
    struct Node *NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->prev=tail;
    NewNode->data=data;
    NewNode->next=NULL;
    if(head==NULL){
        head=tail=NewNode;
        return;
    }
    tail->next=NewNode;
    tail=NewNode;
    printf("\nInserted at end!");
}

void deletespecific(int value){
    struct Node *temp;
    if(head->data==value){
        temp=head;
        head=temp->next;
        if(head != NULL){
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        printf("\n Deleted at first!");
        free(temp);
        return;
    }
    temp=head;
    while(temp!=NULL && temp->data!=value){
        temp=temp->next;
    }

    if(temp == NULL) {
        printf("\nValue not found!");
        return;
    }

    if(tail==temp){
        temp->prev->next=NULL;
        tail=temp->prev;
        free(temp);
        printf("\nDeleted at end!");
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    printf("\nDeletion done!");
}


void display(){
    struct Node *temp = head;

    if(head == NULL){
        printf("\nEmpty List");
        return;
    }

    printf("\nList: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int c, data ,n , target;
    printf("\n 1.Create Linked List \n 2.Insert at First \n 3.Insert at Last \n 4.Delete specific value \n 5.Display \n 6.Exit");

    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &c);

        if(c == 6){
            printf("Exit!");
            break;
        }

        switch(c){
            case 1:
                printf("\nEnter list length: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertfirst(data);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertend(data);
                break;

            case 4:
                printf("\nEnter value to be deleted: ");
                scanf("%d", &target);
                deletespecific(target);
                break;

            case 5:
                display();
                break;

            default:
                printf("Invalid Choice");
        }
    }
}
