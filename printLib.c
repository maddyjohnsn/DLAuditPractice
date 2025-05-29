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
	
	
        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);

	printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

	
	printf_ptr(format);

	dlclose(handle);


        return 0;
}


int sprintf(char *buffer, const char *format, ...){

	//sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*sprintf_ptr)(char *buffer, const char *format, ...) = dlsym(handle, "sprintf");
        if (!sprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }

        //uses my printf and then closes the library! Yay!


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

	gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


	printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);
	
	dlclose(handle2);
	sprintf_ptr(buffer, format);

	dlclose(handle);

        return 0;

}

int dprintf(int fd, const char *format, ...){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*dprintf_ptr)(int fd, const char *format, ...) = dlsym(handle, "dprintf");
        if (!dprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);

	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        dprintf_ptr(fd, format);

        dlclose(handle);

        return 0;

}

int fprintf(FILE *stream, const char *format, ...){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*fprintf_ptr)(FILE *stream, const char *format, ...) = dlsym(handle, "fprintf");
        if (!fprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);

	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        fprintf_ptr(stream, format);

        dlclose(handle);

        return 0;

}

int snprintf(char *str, size_t size,  const char *format, ...){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*snprintf_ptr)(char *str, size_t size, const char *format, ...) = dlsym(handle, "snprintf");
        if (!snprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        snprintf_ptr(str, size, format);

        dlclose(handle);

        return 0;

}

int vprintf(const char *format, va_list ap){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*vprintf_ptr)(const char *format, va_list ap) = dlsym(handle, "vprintf");
        if (!vprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time

	struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        vprintf_ptr(format, ap);

        dlclose(handle);

        return 0;

}

int vfprintf(FILE *stream, const char *format, va_list ap){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*vfprintf_ptr)(FILE *stream, const char *format, va_list ap) = dlsym(handle, "vfprintf");
        if (!vfprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        vfprintf_ptr(stream, format, ap);

        dlclose(handle);

        return 0;

}

int vdprintf(int fd, const char *format, va_list ap){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*vdprintf_ptr)(int fd, const char *format, va_list ap) = dlsym(handle, "vdprintf");
        if (!vdprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        vdprintf_ptr(fd, format, ap);

        dlclose(handle);

        return 0;

}

int vsprintf(char *str, const char *format, va_list ap){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*vsprintf_ptr)(char *str, const char *format, va_list ap) = dlsym(handle, "vsprintf");
        if (!vsprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        vsprintf_ptr(str, format, ap);

        dlclose(handle);

        return 0;

}

int vsnprintf(char *str, size_t size, const char *format, va_list ap){

        //sets up dlopen to open the shared library containing print
        void *handle;

        handle = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*vsnprintf_ptr)(char *str, size_t size, const char *format, va_list ap) = dlsym(handle, "vsnprintf");
        if (!vsnprintf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        //gets the initial time from gettimeofday. tv is the time
        struct timeval tv;

        struct tm *today;

        gettimeofday(&tv, NULL);
        today = localtime(&tv.tv_sec);


	void *handle2;

        handle2 = dlopen("libc.so.6", RTLD_LAZY);
        if (!handle2){
                //if failed to load the library
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
        }


        int (*printf_ptr)(const char *format, ...) = dlsym(handle, "printf");
        if (!printf_ptr) {
                //if symbol can't be found (should be the needed function I'm replacing)
                fprintf(stderr, "Error: %s\n", dlerror());
                dlclose(handle);
                return EXIT_FAILURE;
        }


        printf_ptr("Time: %d:%0d:%0d.%d\n", today->tm_hour, today->tm_min, today->tm_sec, tv.tv_usec);

        dlclose(handle2);


        vsnprintf_ptr(str, size, format, ap);

        dlclose(handle);

        return 0;

}

