#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <dlfcn.h>

//credits to https://www.tutorialspoint.com/what-is-the-ld-preload-trick-on-linux
//credits to https://gist.github.com/tailriver/30bf0c943325330b7b6a for help with DLopen


int printf(const char *format, ...){
	
	//sets up dlopen to open the shared library containing print
	void *handle;

	handle = dlopen("libc.so.6", RTLD_LAZY);
	if (!handle){
		//if failed to load the library
		fprintf(stderr, "Error: %s\n", dlerror());
		return EXIT_FAILURE;
	}

	//myPrintf = dlsym(handle, "printf");
	
	int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
	if (!printf_ptr) {
        	//if symbol can't be found (should be the needed function I'm replacing)
        	fprintf(stderr, "Error: %s\n", dlerror());
        	dlclose(handle);
        	return EXIT_FAILURE;
    	}

	//uses my printf and then closes the library! Yay!
	
	//printf_ptr("ok bang");

	dlclose(handle);

	
        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);

        //gets all needed time components
        double  hour = today->tm_hour;
        char buffer[50];


        double min = today->tm_min;
        char buffer2[50];

        double sec = today->tm_sec;
        char buffer3[50];

        double msec = tv.tv_usec;
        char buffer4[50];

        //converts time components to strings
        sprintf(buffer, "%f", hour);
        sprintf(buffer2, "%f", min);
        sprintf(buffer3, "%f", sec);
        sprintf(buffer4, "%f", msec);

        //Gets rid of trailing 0s
        int length = strlen(buffer);
        buffer[length-7] = '\0';

        int length2 = strlen(buffer2);
        buffer2[length2-7] = '\0';

	 int length3 = strlen(buffer3);
        buffer3[length3-7] = '\0';

        int length4 = strlen(buffer4);
        buffer4[length4-7] = '\0';

        //concatonates time stamp
        char stamp[50] = "Time stamp: ";
        strcat(stamp, buffer);
        strcat(stamp, ":");
        strcat(stamp,buffer2);
        strcat(stamp, ":");
        strcat(stamp,buffer3);
        strcat(stamp, ":");
        strcat(stamp,buffer4);
        puts(stamp);

        //prints original message
        va_list args;
        va_start(args, format);
        //vprintf(format, args);
        puts(format);
        //vprintf("", args);
        va_end(args);

        return 0;
}



