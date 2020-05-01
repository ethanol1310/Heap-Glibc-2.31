#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	unsigned long fake_chunk[56];
	fprintf(stderr, "fake_chunk: %p\n", fake_chunk);
	unsigned long *buf1 = malloc(128);
	unsigned long *buf2 = malloc(256);

	fprintf(stderr, "buf1: %p\n", buf1);
	fprintf(stderr, "buf2: %p\n", buf2);
	free(buf1);

	void *buf3 = malloc(1200);
	fprintf(stderr, "buf3: %p\n", buf3);

	fake_chunk[2] = (unsigned long)buf1 - 0x10;
	fake_chunk[3] = (unsigned long)&fake_chunk[4];
	fake_chunk[6] = (unsigned long)fake_chunk;

	buf1[1] = (unsigned long)fake_chunk;

	void *buf4 = malloc(128);
	char *buf5 = malloc(128);

	fprintf(stderr, "buf4: %p\n", buf4);
	fprintf(stderr, "buf5: %p\n", buf5);
	fprintf(stderr, "buf5: ");
	read(STDIN_FILENO, buf5, 128);
	return 0;
}
