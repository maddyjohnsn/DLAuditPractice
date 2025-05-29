#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void vprinting(const char *format, ...){
	va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);

}

int main(void){

	printf("practice");

	printf("yes!");

	char buffer[100];
	int rand = 10;
	sprintf(buffer, "Add this and a number: %d", rand);
	printf("%s\n", buffer);

	vprinting ("Hello! %s\n", "world");


	return 0;
}
