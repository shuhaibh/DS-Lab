#include <stdio.h>
int front=-1,rear=-1,size,A[50];
void enqueue(int item)
{
        if (rear==size-1)
                printf("Queue is Full!\n");
        else if (rear==-1)
        {
                rear=0;
                front=0;
                A[rear]=item;
        }
        else
        {
                rear++;
                A[rear]=item;
        }
}

void dequeue()
{
        int item;
        if(front==-1)
                printf("The queue is Empty!\n");
        else if(front==rear)
        {
                item=A[front];
                printf("DEqueued %d from queue\n",item);
                front=-1;
                rear=-1;
        }
        else
        {
                item=A[front];
                printf("DEqueued %d from queue\n",item);
                front++;
        }

}

void display()
{
        if(front==-1)
                printf("The queue is empty!\n");
        else
        {
                printf("The Queue:-\n\t");
                int i;
                for(i=front;i<=rear;i++)
                        printf("%d\t",A[i]);
                printf("\n");
        }
}

void main()
{
        int ch,val;
        printf("Enter the no of Elements in Queue\n");
        scanf("%d",&size);
        while(ch!=4)
        {
                printf("Queue Opaerations:-\n");
                printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.Exit\n");
                printf("Enter your choice:-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("Enter the element to enqueue:-");
                                scanf("%d",&val);
                                enqueue(val);
                                break;
                        case 2: dequeue();
                                break;
                        case 3: display();
                                break;
                        case 4: printf("-----Exiting program!....\n");
                                break;
                        default:printf("-----Invalid choice!\n");
                }
        }
}
