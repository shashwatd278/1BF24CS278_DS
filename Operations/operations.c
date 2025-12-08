#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int data;

    *head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("\nMemory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void SortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node **head) {
    struct Node *prev = NULL, *nextNode = NULL, *curr = *head;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    *head = prev;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main() {
    int c, n;
    struct Node *head1 = NULL;

    printf("\n1. Create Linked List");
    printf("\n2. Sort the List");
    printf("\n3. Reverse the List");
    printf("\n4. Concatenate Two Lists");
    printf("\n5. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &c);

        if (c == 5) {
            printf("Exit!\n");
            break;
        }

        switch (c) {
            case 1:
                printf("\nEnter list length: ");
                scanf("%d", &n);
                create(&head1, n);
                printf("List: ");
                display(head1);
                break;

            case 2:
                if (head1 == NULL) {
                    printf("List not created yet!\n");
                    break;
                }
                SortList(head1);
                printf("Sorted List: ");
                display(head1);
                break;

            case 3:
                if (head1 == NULL) {
                    printf("List not created yet!\n");
                    break;
                }
                reverseList(&head1);
                printf("Reversed List: ");
                display(head1);
                break;

            case 4: {
                struct Node *head2 = NULL;
                struct Node *head3 = NULL;

                if (head1 == NULL) {
                    printf("First list not created yet!\n");
                    break;
                }

                printf("\nEnter length of second list: ");
                scanf("%d", &n);
                create(&head2, n);

                head3 = concatenate(head1, head2);
                printf("\nConcatenated List:\n");
                display(head3);
                break;
            }

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

