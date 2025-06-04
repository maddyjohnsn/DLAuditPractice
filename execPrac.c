
#include<stdio.h>
#include<unistd.h>

int main(){

	printf("Good!\n");
	char *args[]= {"./a.out", NULL};
	execv(args[0], args);
	printf("Bad\n");
	return 0;
}
