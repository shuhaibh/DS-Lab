//Program to find Sparse Matrix of any given matrix
#include <stdio.h>

void Sparse(int A[20][20],int,int);
void main()
{
        int m,n,i,j,A[20][20];
        printf("Enter the size of matrix:-\n");
        scanf("%d%d",&m,&n);
        printf("Enter the Elements of the matrix:-\n");
        for(i=0;i<m;i++)
                for(j=0;j<n;j++)
                        scanf("%d",&A[i][j]);
        printf("The given Matrix:-\n");
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        printf("\t%d",A[i][j]);
                }
                printf("\n");
        }
        Sparse(A,m,n);
}

void Sparse(int A[20][20],int m,int n)
{
        int i,j,k=1;
        int S[10][10];
        S[0][0]=m;
        S[0][1]=n;
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(A[i][j]!=0)
                        {
                                S[k][0]=i;
                                S[k][1]=j;
                                S[k][2]=A[i][j];
                                k++;
                        }
                }
        }
        S[0][2]=k-1;
        //Printing the Sparse Matrix
        printf("Sparse matrix:-\n");
        for(i=0;i<k;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("\t%d",S[i][j]);
                }
                printf("\n");
        }
}
