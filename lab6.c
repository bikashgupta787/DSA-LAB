#include <stdio.h>
#include <stdlib.h>

void printRandoms(int lower, int upper,
							int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %
		(upper - lower + 1)) + lower;
		printf("%d ", num);
	}
}

int main()
{
	int lower = 1, upper = 200, count = 100;

	printRandoms(lower, upper, count);

	return 0;
}



