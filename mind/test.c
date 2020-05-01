#include <stdio.h>
int sum(int a, int b) {
	int c = 4;
	int d = 3;
	int sum = a + b + c + d;
	return sum;
}

int main() {

	int a = 5, b = 6;
	sum(a, b);
	return 0;
}
