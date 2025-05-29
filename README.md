# DLAuditPractice

DLAuditPractice contains c shared libraries for overriding c's built in printf functions with LD Preload. 

## timeLib.c

Usage:
> gcc timeLib.c -o timeLib

This contains basic print functions to test the functionality of printLib.c and newPrint.c

## newPrint.c

Usage:
> gcc -shared -fPIC -o newPrint.so newPrint.c
>LD_PRELOAD=$PWD/newPrint.so ./timeLib


Basic code to be turned into a shared library to insert a timestamp whenever printf is called before the original printf statement

## printLib.c

Usage:
> gcc -shared -fPIC -o printLib.so printLib.c -ldl
>LD_PRELOAD=$PWD/printLib.so ./timeLib 

Shared library code that overrides all printf variations to input a timestamp before the original print statement

 
