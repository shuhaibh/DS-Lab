//Program to implement Priority Queue
#include <stdio.h>

int front,rear,size;

struct PQ
{
        int item;
        int priority;
}A[20];

void enqueue(int Item,int prio)
{
        int i,loc;
        if(front==0 && rear==size-1)
        {
                printf("The queue is full");
        }
        else if(front==-1)
        {
                front=0;
                rear=0;
                A[rear].item=Item;
                A[rear].priority=prio;
        }
        else
        {
                if(rear==size-1)
                {
                        for(i=front;i<=rear;i++)
                                A[i-1]=A[i];
                        front--;
                        rear--;
                }
                for(i=rear;i>=front;i--)
                {
                        if(A[i].priority<prio)
                                break;
                }
                loc=i+1;
                for(i=rear;i>=loc;i--)
                {
                        A[i+1]=A[i];
                }
                A[loc].item=Item;
                A[loc].priority=prio;
                rear++;
        }
}

void dequeue()
{
        if(front==-1)
                printf("The queue is Empty!\n");
        else if(front==rear)
        {
                printf("DEqueued %d from queue\n",A[front].item);
                front=-1;
                rear=-1;
        }
        else
        {
                printf("DEqueued %d from queue\n",A[front].item);
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
                        printf("%d\t",A[i].item);
                printf("\n");
        }
}

void main()
{
        int prio,ch,val;
        front=-1;
        rear=-1;
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
                        case 1: printf("Enter the Element and Priority:-");
                                scanf("%d%d",&val,&prio);
                                enqueue(val,prio);
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
