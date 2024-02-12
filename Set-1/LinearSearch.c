//Program to implement Linear Search
#include <stdio.h>

int main()
{
        int key,flag=0,i,A[20],size;

        //Inputting from the user
        printf("Enter the no of elements:-\n");
        scanf("%d",&size);
        printf("Enter the Elements:-\n");
        for(i=0;i<size;i++)  
                scanf("%d",&A[i]);
        printf("Enter the element to search:-\n");
        scanf("%d",&key);
        //Searching the element
        for(i=0;i<size;i++)
        {
                if(A[i]==key)
                {
                        flag=1;
                        break;
                }
        }
        if(flag==1)
                printf("The element is present at position %d\n",i+1);
        else
                printf("The element is not found\n");
}
