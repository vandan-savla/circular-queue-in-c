#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void peek();
void disp();

int main()
{
    int op;
    while (op != 5)
    {
        printf("\n******MAIN MENU*****\n");
        printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        printf("CHOOSE OPTION => ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            disp();
            break;
        case 5:
            exit(0);
        default:
            printf("wrong choice\n");
            break;
        }
    }
    return 0;
}
void enqueue()
{
    int num;
    printf("Enter a no to insert: ");
    scanf("%d", &num);
    if ((front == 0 && rear == MAX - 1) || rear == front - 1)
    {
        printf("OVERFLOW\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
    }
    queue[rear] = num;
}

void dequeue()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("UNDERFLOW\n");
    }
    val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }

    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
            front++;
    }
    printf("Deleted Element is %d \n", val);
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("front element is %d \n", queue[front]);
    }
}

void disp()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("EMPTY\n");
    }
    else
    {
        if (front < rear)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
        else
        {
            // if 1 2 3 4 5 was og queue
            // and 4 5 removed and 6 7 added then front is at 3 and rear at 5 i.e 3 4 5 6 7
            // this prints 3 to 5
            for (i = front; i < MAX; i++)
            {
                printf("%d ", queue[i]);
            }
            // then this prints from start to rear
            // from 6 to 7
            for (i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }
}
