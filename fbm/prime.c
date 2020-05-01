#include <stdio.h>
#include <stdlib.h>

int fvuln() {
	char *ptr = malloc(1024);
	char *ptr2;

	// ptr & ~(HEAP_MAX_SIZE - 1) = 0x600000
	int heap = (int)ptr & 0xFFF00000;
	_Bool found = 0;

	printf("ptr found at %p\n", ptr);

	for (int i = 2; i < 1024; i++) {
		/* Allocate chunks up to 610000 */
		if (!found && (((int)(ptr2 = malloc(1024)) & 0xFFF00000) == \
					(heap + 0x100000))) {
			printf("good heap allignment found on malloc () %i (%p)\n", i, ptr2);
			found = 1;
			break;
		}
	}

	malloc(1024);
	fread(ptr, 1024 * 1024, 1, stdin);

	free(ptr);
	free(ptr2);
	return 0;
}

int main() {
	int i, n, ret;
        char *s, buf[128];
	fvuln();
	return 0;
}
