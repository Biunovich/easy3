#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
typedef struct Comlex
{
	double Re;
	double Im;
} Comlex;
Comlex plus(Comlex x,Comlex y);
Comlex minus(Comlex x,Comlex y);
Comlex devide(Comlex x,Comlex y);
Comlex mult(Comlex x,Comlex y);
