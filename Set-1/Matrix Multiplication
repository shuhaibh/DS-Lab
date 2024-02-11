//Program to implement Matrix Multiplication
#include <stdio.h>

void Display(int A[20][20],int m,int n);
void main()
{
        int m,n,p,q,i,j,k,A[20][20],B[20][20],C[20][20];

        printf("Enter the size of Matrix A:-\n");
        scanf("%d%d",&m,&n);
        printf("Enter the size of Matrix b:-\n");
        scanf("%d%d",&p,&q);

        //checking if multiplication is possible or not
        if(n!=p)
                printf("Multiplication is not possible!\n");

        else
        {
                printf("Enter the elements of Matrix A:-\n");
                for(i=0;i<m;i++)
                        for(j=0;j<n;j++)
                                scanf("%d",&A[i][j]);
                printf("Enter the elements of Matrix B:-\n");
                for(i=0;i<p;i++)
                        for(j=0;j<q;j++)
                                scanf("%d",&B[i][j]);
                //Multiplying and Storing to matrix C
                for(i=0;i<m;i++)
                        for(j=0;j<q;j++)
                        {
                                C[i][j]=0;
                                for(k=0;k<n;k++)
                                        C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
                        }
                //Displaying
                printf("Matrix A:-\n");
                Display(A,m,n);
                printf("Matrix B:-\n");
                Display(B,p,q);
                printf("Matrix C:-\n");
                Display(C,m,q);
        }
}
void Display(int A[20][20],int m,int n)
{
        int i,j;
        for(i=0;i<m;i++)
        {
                printf("\t");
                for(j=0;j<n;j++)
                {
                        printf("%d\t",A[i][j]);
                }
                printf("\n");
        }
}
