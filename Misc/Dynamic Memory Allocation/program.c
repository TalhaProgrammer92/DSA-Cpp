#include <stdio.h>
#include <stdlib.h>

int main()
{
	// ? Memomry Allocation (Variable)
	int *x = (int*) /* Type casting is optional */ malloc(sizeof(int));

	// * Assigning value to the allcated memory
	*x = 5;

	// * Print the value
	printf("Value: %d\n", *x);

	// ? Memomry Allocation (Array)
	const int size = sizeof(int), blocks = *x;
	int *y = (int*) calloc(5, 2);

	// * Assigning values
	for (int i = 0; i < blocks; i++)
		*(y + i) = i + 1;

	// * Printing values
	printf("Array: ");
	for (int i = 0; i < blocks; i++)
		printf("%d ", *(y + i));
	printf("\n");

	// ? Reallocate memory
	const int extend = blocks + 3;
	y = (int*) realloc(y, extend);

	for (int i = 0; i < extend; i++)
		*(y + i) = i + 1;

	printf("Array: ");
	for (int i = 0; i < extend; i++)
		printf("%d ", *(y + i));
	printf("\n");

	// ? Free the allocated memory
	free(x);
	free(y);
	x = y = NULL;

	return 0;
}
