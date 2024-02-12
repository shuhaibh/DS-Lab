//Program to implement Stack
#include <stdio.h>
int top=0,size=0,A[50];

void push(int item)
{
        if(top==size)
                printf("-----Stack Overflow!\n");
        else
        {
                top++;
                A[top]=item;
        }
}

void pop()
{
        int item;
        if(top==0)
                printf("------Stack Underflow!\n");
        else
        {
                item=A[top];
                top--;
                printf("---Popped %d from Stack\n",item);
        }
}

void display()
{
        int i;
        if(top==0)
                printf("---The Stack is empty!\n");
        else
        {
                printf("The Stack:-\n\t");
                for(i=1;i<=top;i++)
                        printf("%d\t",A[i]);
                printf("\n");
        }
}

void main()
{
        int ch,val;
        printf("Enter the no of Elements in Stack\n");
        scanf("%d",&size);
        while(ch!=4)
        {
                printf("Stack Opaerations:-\n");
                printf("1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\n");
                printf("Enter your choice:-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("Enter the element to push:-");
                                scanf("%d",&val);
                                push(val);
                                break;
                        case 2: pop();
                                break;
                        case 3: display();
                                break;
                        case 4: printf("-----Exiting program!....\n");
                                break;
                        default:printf("-----Invalid choice!\n");
                }
        }
}
