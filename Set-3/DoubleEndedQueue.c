//Program to implement Double ended Queue
#include <stdio.h>

int size,front,rear,A[10];

void push(int);
void pop();
void inject(int);
void reject();
void display();

void main()
{
        int ch,val;
        front=-1;
        rear=-1;
        printf("Enter the no of Elements in Queue\n");
        scanf("%d",&size);
        while(ch!=6)
        {
                printf("Queue Opaerations:-\n");
                printf("1.PUSH\n2.INSERT\n3.POP\n4.REJECT\n5.DISPLAY\n6.EXIT\n");
                printf("Enter your choice:-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("Enter the element to push:-");
                                scanf("%d",&val);
                                push(val);
                                break;
                        case 2: printf("Enter the value to insert:-");
                                scanf("%d",&val);
                                inject(val);
                                break;
                        case 3: pop();
                                break;
                        case 4: reject();
                                break;
                        case 5: display();
                                break;
                        case 6: printf("-----Exiting program!....\n");
                                break;
                        default:printf("-----Invalid choice!\n");
                }
        }
}

void push(int item)
{
        int i;
        if (front==0 && rear==size-1)
                printf("The Queue is full\n");
        else if (rear==-1)
        {
                front=0;
                rear=0;
                A[front]=item;
        }
        else if(front>0)
        {
                front--;
                A[front]=item;
        }
        else
        {
                for(i=rear;i>=front;i--)
                {
                        A[i+1]=A[i];
                }
                A[front]=item;
                rear++;
        }
}

void inject(int item)
{
        int i;
        if(front==0 && rear==size-1)
                printf("The queue is full");
        else if(rear==-1)
        {
                front=0;
                rear=0;
                A[rear]=item;
        }
        else if(rear<size-1)
        {
                rear++;
                A[rear]=item;
        }
        else
        {
                for(i=front;i<=rear;i++)
                {
                        A[i-1]=A[i];
                }
                A[rear]=item;
                front--;
        }
}

void pop()
{
        if (front==-1)
                printf("The queue is Empty\n");
        else if(front==rear)
        {
                printf("The deleted item is %d \n",A[front]);
                front=-1;
                rear=-1;
        }
        else
        {
                printf("The deleted item is %d \n",A[front]);
                front++;
        }
}

void reject()
{
        if (rear==-1)
                printf("The queue is Empty\n");
        else if(front==rear)
        {
                printf("The deleted item is %d \n",A[rear]);
                front=-1;
                rear=-1;
        }
        else
        {
                printf("The deleted item is %d \n",A[rear]);
                rear--;
        }
}

void display()
{
        int i;
        if(front==-1)
                printf("The queue is empty!\n");
        else
        {
                printf("The Queue:-\n\t");
                for(i=front;i<=rear;i++)
                        printf("%d\t",A[i]);
                printf("\n");
        }
}
