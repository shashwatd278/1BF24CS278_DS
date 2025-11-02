#include <stdio.h>
#define N 5
int stack[N];
int top = -1;

void PUSH()
{
    int x;
    printf("Enter data");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void POP()
{
    int item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("%d \n", item);
    }
}

void PEEK()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d \n", stack[top]);
        top--;
    }
}

int main()
{
    int choice;
    printf("1.Push\n2.Pop\n3.Peak\n4.Exit\n");
    printf("Enter a choice");
    scanf("%d", &choice);
   
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            PUSH();
            break;

        case 2:
            POP();
            break;

        case 3:
            PEEK();
            break;

        default:
            printf("Invalid Choice");
            break;
        }
        printf("Enter a choice");
        scanf("%d", &choice);
    }
    printf("Exit");
    return 0;
}