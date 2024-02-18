//Program to implement Linked List                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              LL.c                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        #include <stdio.h>
#include <stdlib.h>
#define null NULL

struct node
{
        int data;
        struct node *link;
};

void display();

struct node *head;

void insert_front(int x)
{
        struct node *new;
        new=(struct node *)malloc(sizeof(struct node));
        new->data=x;
        new->link=head;
        head=new;
        display();
}

void insert_end(int x)
{
        struct node *new,*ptr;
        new=(struct node *)malloc(sizeof(struct node));
        new->data=x;
        new->link=null;
        if(head==null)
                head=new;
        else
        {
                ptr=head;
                while(ptr->link!=null)
                        ptr=ptr->link;
                ptr->link=new;
        }
        display();
}

void insert_after(int key,int x)
{
        struct node *ptr,*new;
        if(head==null)
                printf("Search key not found!Insertion is not possible\n");
        else
        {
                ptr=head;
                while(ptr->data!=key && ptr->link!=null)
                        ptr=ptr->link;
                if(ptr->data!=key)
                        printf("Search key not found!Insertion is not possible\n");
                else
                {
                        new=(struct node *)malloc(sizeof(struct node));
                        new->data=x;
                        new->link=ptr->link;
                        ptr->link=new;
                }
        }
        display();
}

void delete_front()
{
        struct node *temp;
        if(head==null)
                printf("The linked list is empty!");
        else
        {
                temp=head;
                head=head->link;
                free(temp);
        }
        display();
}

void delete_end()
{
        struct node *pre,*curr,*temp;
        if(head==null)
                printf("The linked list is empty!\n");
        else if(head->link==null)
        {
                temp=head;
                head=null;
                free(temp);
        }
        else
        {
                pre=head;
                curr=head->link;
                while(curr->link!=null)
                {
                        pre=curr;
                        curr=curr->link;
                }
                pre->link=null;
                free(curr);
        }
        display();
}

void delete_any(int key)
{
        struct node *pre,*curr,*temp;
        if(head==null)
                printf("Linked list is empty!\n");
        else
        {
                pre=head;
                curr=head->link;
                while(curr->data!=key && curr->link!=null)
                {
                        pre=curr;
                        curr=curr->link;
                }
                if(curr->data!=key)
                        printf("Element not found!\n");
                else
                {
                        pre->link=curr->link;
                        free(curr);
                }
        }
        display();
}

void display()
{
        struct node *ptr;
        if(head==null)
                printf("The Linked list is empty!\n");
        else
        {
                printf("The elements in Linked List:-\n\t");
                ptr=head;
                while(ptr!=null)
                {
                        printf("%d\t",ptr->data);
                        ptr=ptr->link;
                }
                printf("\n");
        }
}

void main()
{
        int opt,x,key;
        while(opt!=8)
        {
                printf("Choose the Operation:-\n");
                printf("1.Insert at Front\n2.Insert at End\n3.Insert After\n4.Delete from Front\n5.Delete from End\n6.Delete specific value\n7.Display\n8.Exit\n");
                printf("Enter your choice:-");
                scanf("%d",&opt);
                switch(opt)
                {
                        case 1: printf("Enter the value to insert:-");
                                scanf("%d",&x);
                                insert_front(x);
                                break;
                        case 2: printf("Enter the value to insert:-");
                                scanf("%d",&x);
                                insert_end(x);
                                break;
                        case 3: printf("Enter the value to insert:-");
                                scanf("%d",&x);
                                printf("Enter the value after to insert:-");
                                scanf("%d",&key);
                                insert_after(key,x);
                                break;
                        case 4: delete_front();
                                break;
                        case 5: delete_end();
                                break;
                        case 6: printf("Enter the element to delete");
                                scanf("%d",&key);
                                delete_any(key);
                                break;
                        case 7: display();
                                break;
                        case 8: printf("----Exiting program!\n");
                                break;
                        default:printf("----Invalid Choice!\n");
                                break;
                }
        }
}
