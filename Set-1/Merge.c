/*Program to Merge two given Ascending ordered Arrays*/

#include <stdio.h>

int main() 
{
	int p, q, s, A[30], B[30], C[60], i, j, k;

  //Taking in first Array
	printf("Enter size of A: ");
	scanf("%d", &p);
	printf("Enter numbers: ");
	for (i = 0; i < p; i++)
		scanf(" %d", &A[i]);

  //Taking in second Array
	printf("Enter size of B: ");
	scanf(" %d", &q);
	printf("Enter numbers: ");
	for (i = 0; i < q; i++)
		scanf(" %d", &B[i]);

	s = p + q;
	i = 0, j = 0, k = 0;

  //Merging
	while (i < p && j < q) {
		if (A[i] < B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	}

	while (i < p)
		C[k++] = A[i++];

	while (j < q)
		C[k++] = B[j++];
  
  //Printing the merged array
	printf("Merged list is: ");
	for (i = 0; i < s; i++)
		printf("%d ", C[i]);

	printf("\n");
}
