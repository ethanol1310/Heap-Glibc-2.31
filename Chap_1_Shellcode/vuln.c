#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vuln(char *str) {
	char buf[10];
	strcpy(buf, str);
}

int main(int argc, char **argv) {
	char str[512];
	FILE *exploit;

	exploit = fopen("exploit", "r");
	fread(str, sizeof(char), 512, exploit);
	vuln(str);

	return 0;
}
