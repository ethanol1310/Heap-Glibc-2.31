#include <stdio.h>
#include <stdlib.h>

int main()
{

	int *a = malloc(128);
	free(a);
	return 0;
}
