#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>

void printName(void) {

	
	printf("±è³«Çö\n");
	return;
}

int add(int x, int y) {
	int sum = 0;
	sum = x + y;
	return sum;
}

int main() {
	
	printName();
	int sum = add(10, 1);
	printf("%d\n", sum);
	return 0;
}
