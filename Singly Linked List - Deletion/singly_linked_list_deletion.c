#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int n){
    struct Node *NewNode, *temp;
    int data;

    if(n <= 0){
        printf("\nInvalid Length");
        return;
    }

    head = NULL;

    for(int i = 1; i <= n; i++){
        NewNode = (struct Node*)malloc(sizeof(struct Node));
        if(NewNode == NULL){
            printf("\nNo Memory present");
            return;
        }

        printf("\nEnter data: ");
        scanf("%d", &data);

        NewNode->data = data;
        NewNode->next = NULL;

        if(head == NULL){
            head = NewNode;
            temp = head;
        } else {
            temp->next = NewNode;
            temp = NewNode;
        }
    }
}

void deletefirst(){
    struct Node *temp;
    if (head==NULL){
        printf("\nEmpty list");
        return;
    }

    temp=head;
    head=head->next;
    printf("\nDeleted at first is %d", temp->data);
    free(temp);
}

void deletespecific(int target){
    struct Node *temp, *prev;
    temp=head;
    if (head==NULL){
        printf("\nEmpty list");
        return;
    }

    if(head->data == target){
        deletefirst();
    }

    while(temp->next != NULL && temp->data !=target){
        prev=temp;
        temp=temp->next;
    }

    prev->next=temp->next;
    printf("\nDeleted element is %d", temp->data);
    free(temp);
}

void deletelast(){
    struct Node *temp, *prev;
    temp=head;
    if (head==NULL){
        printf("\n Empty list");
        return;
    }

    while(temp->next != NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("\nDeleted element is %d", temp->data);
    free(temp);
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

void main(){
    int c, target, n;
    printf("\n 1.Create Linked List \n 2.Delete at First \n 3.Delete specific value \n 4.Delete at Last \n 5.Display \n 6.Exit");
    printf("\nEnter choice: ");
    scanf("%d", &c);

    while(c!=6){
        switch(c){
            case 1:
                printf("\nEnter list length: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                deletefirst();
                break;

            case 3:
                printf("\nEnter value to be deleted: ");
                scanf("%d", &target);
                deletespecific(target);
                break;

            case 4:
                deletelast();
                break;

            case 5:
                display();
                break;

            default:
                printf("\nInvalid Choice");
        }
        printf("\nEnter choice: ");
        scanf("%d", &c);
    }
    printf("Exit !");
    return;
}
