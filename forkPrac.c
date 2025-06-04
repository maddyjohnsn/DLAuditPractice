/* to make mkfifo work:*/
//in one terminal, type mkfifo name
//desired command > name
//
//in the other terminal: type cat < name


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	pid_t p = fork();
	if(p<0){
		perror("fork fail");
 		exit(1);
    	}
    	printf("Hello world!, process_id(pid) = %d \n",getpid());
    	return 0;
}
