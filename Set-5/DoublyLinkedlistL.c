//Program to implement Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev; 
};

void display();

struct node *head;

void insert_front(int x)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = head;
    newNode->prev = NULL;  // The new node is the first node, so its previous pointer is NULL

    if (head != NULL)
        head->prev = newNode;  // Update previous pointer of the current head

    head = newNode;
    display();
}

void insert_end(int x)
{
    struct node *newNode, *lastNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        lastNode = head;
        while (lastNode->next != NULL)
            lastNode = lastNode->next;

        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    display();
}

void insert_after(int key, int x)
{
    struct node *ptr, *newNode;
    if (head == NULL)
    {
        printf("Linked list is empty! Cannot insert after.\n");
        return;
    }

    ptr = head;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Key not found! Cannot insert after.\n");
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != NULL)
    {
        ptr->next->prev = newNode;
    }

    ptr->next = newNode;

    display();
}

void delete_front()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The linked list is empty! Cannot delete from the front.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);

    display();
}

void delete_end()
{
    struct node *lastNode, *secondLastNode;
    if (head == NULL)
    {
        printf("The linked list is empty! Cannot delete from the end.\n");
        return;
    }

    lastNode = head;
    secondLastNode = NULL;

    while (lastNode->next != NULL)
    {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }

    if (secondLastNode == NULL)
    {
        // Only one node in the list
        head = NULL;
    }
    else
    {
        secondLastNode->next = NULL;
    }

    free(lastNode);

    display();
}

void delete_any(int key)
{
    struct node *ptr, *prev, *temp;
    if (head == NULL)
    {
        printf("Linked list is empty! Cannot delete.\n");
        return;
    }

    ptr = head;
    prev = NULL;

    while (ptr != NULL && ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Element not found! Cannot delete.\n");
        return;
    }

    if (prev == NULL)
    {
        // Deleting the first node
        head = ptr->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        prev->next = ptr->next;
        if (ptr->next != NULL)
        {
            ptr->next->prev = prev;
        }
    }

    free(ptr);

    display();
}

void display()
{
    struct node *ptr;
    if (head == NULL)
        printf("The Doubly Linked list is empty!\n");
    else
    {
        printf("The elements in Doubly Linked List:-\n\t");
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
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
        
        return 0;
}
