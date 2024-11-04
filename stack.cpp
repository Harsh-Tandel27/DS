#include <stdio.h>
#define size 5

int stack[size];
int top = -1;

void push()
{
    int val;
    if (top == size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        printf("Enter value :");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("\nValuse in stack are :\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d \n", stack[i]);
        }
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("Poped%d\n", stack[top]);
        top--;
    }
}

void Peek()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

int main()
{
    int ch;
    while (ch != 5)
    {
        printf("\n_____MENU______\n");
        printf("\nEnter Choice\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    return 0;
}