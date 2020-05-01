#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fvuln(unsigned long len, char *str) {
	char *ptr1, *ptr2, *ptr3;

	ptr1 = malloc(256);
	printf("\nPTR1 = [ %p ]\n", ptr1);
	strcpy(ptr1, str);

	printf("\Allocated MEM: %u bytes", len);;
	ptr2 = malloc(len);
	ptr3 = malloc(256);

	strncpy(ptr3, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 256);
}

int main(int argc, char *argv[]) {
	char *pEnd;
	if (argc == 3)
		fvuln(strtoull(argv[1], &pEnd, 10), argv[2]);
	return 0;
}
