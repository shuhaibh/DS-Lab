//Program ot find transpose of a given tuple matrix
#include <stdio.h>

int S[20][20],T[20][20];

void Sparse(int A[20][20],int,int);
void Transpose();

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
        Transpose();
}

void Sparse(int A[20][20],int m,int n)
{
        int i,j,k=1;
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
//findindg transpose of the sparse

void Transpose()
{
        int m,n,k,i,j;
        T[0][0]=S[0][1];
        T[0][1]=S[0][0];
        T[0][2]=S[0][2];

        k=1;
        m=S[0][1];
        n=S[0][2];

        for(i=0;i<=m;i++)
                for(j=0;j<=n;j++)
                {
                        if(S[j][1]==i)
                        {
                                T[k][0]=S[j][1];
                                T[k][1]=S[j][0];
                                T[k][2]=S[j][2];
                                k++;
                        }
                }
        //printing the transpose matrix
        printf("Transpose matrix:-\n");
        for(i=0;i<k;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("\t%d",T[i][j]);
                }
                printf("\n");
        }
}
