//Program to find the smallest number from the given numbers
#include <stdio.h>

int main()
{
	int list[100], n, min, i;
  
  //inputting number of elements
	printf("Enter number of elements: ");
	scanf(" %d", &n);

  //Inputting the numbers
	printf("Enter numbers: ");
	for(i=0; i<n; i++)
		scanf(" %d", &list[i]);

	min = list[0];

  //finding the smallest
	for(i=0; i<n; i++)
  {
		if(ls[i] < min)
    {
			min = ls[i];
		}
  }

	printf("Smallest number is: %d\n", min);
}
