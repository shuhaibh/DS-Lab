//Program to implement Binaru Search
#include <stdio.h>

void main()
{
        int mid,front=0,key,flag=0,end,size,A[20],i;

        printf("Enter the no of elements:-\n");
        scanf("%d",&size);
        end=size-1;
        printf("Enter the Elements:-\n");
        for(i=0;i<size;i++)
                scanf("%d",&A[i]);
        printf("Enter the element to search:-\n");
        scanf("%d",&key);
        while(front<=end)
        {
                mid=(front+end)/2;
                if(key<A[mid])
                        end=mid-1;
                else if(key>A[mid])
                        front=mid+1;
                else
                {
                        flag=1;
                        break;
                }
        }
        if(flag==1)
                printf("The element is present at position %d\n",mid+1);
        else
                printf("The element is not present\n");
}
