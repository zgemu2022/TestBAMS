#include <stdio.h>


#include <dlfcn.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "bams_main.h"
#define LIB_MODTCP_PATH "/usr/lib/libbams_rtu.so"
PARA_BAMS para_bams={1,{9600,9600},{2,2},{6,0}};
typedef int (*init_fun)(void*);
void bams_Init(PARA_BAMS* para)
{	
	void *handle;
	char *error;
    init_fun  my_func = (void *)0;
 	//打开动态链接库
 	 handle = dlopen(LIB_MODTCP_PATH, RTLD_LAZY);
 	if (!handle) {
 		fprintf(stderr, "%s\n", dlerror());
 		exit(EXIT_FAILURE);
 	}
	dlerror();

	*(void **) (&my_func) = dlsym(handle, "bams_main");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}
    my_func(para);

	printf("打开动态链接库成功！！！\n");

}
 
int main(void)
{

	printf("12345 ssdlh\n");
	bams_Init(&para_bams);
	while(1)
	{
		
	}
	return 0;
}