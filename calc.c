#include "1.h"
char ** split(char ** oper,int size)
{
	int i,j;
	char ** oper1 = calloc(sizeof(char*),size);
	for (i=0;i<size;i++){
		oper1[i] = calloc(sizeof(char),10);
		for (j=3;oper[i][j]!='.';j++)
			oper1[i][j-3] = oper[i][j];
	}
	return oper1;
} 
int main(void)
{
	Comlex first,second,result;
	int op;
	char libdir[20];
	int i=0,j,sizedir;
	void *dis;
	DIR * dir;
	char **oper;
	struct dirent *entry;
	dir = opendir("./plugins");
	while ( (entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		    printf("\n%d %s",i++,entry->d_name);
	}
	sizedir = i;
	oper = calloc(sizeof(char*),i);
	for (j = 0; j < i; j++)
		oper[j] = calloc(sizeof(char),10);
	dir = opendir("./plugins");
	j=0;
	while ( (entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		    oper[j++] = entry->d_name;
	}
	oper = split(oper,sizedir);
    printf("\n----------------------------\n");
	Comlex (*funk)(Comlex,Comlex);
	while(1)
	{
		printf("Enter first complex number: ");
		scanf("%lf%lf",&first.Re,&first.Im);
		printf("Enter second complex number: ");
		scanf("%lf%lf",&second.Re,&second.Im);
		for (i=0;i<sizedir;i++)
			printf("%d) %s\n",i,oper[i]);
		printf("Choose operation: ");
		scanf(" %d",&op); 
		sprintf(libdir,"./plugins/lib%s.so",oper[op]);
        printf("%s\n",libdir);
        dis = dlopen(libdir,RTLD_NOW);
        funk = dlsym(dis,"run");
        result = funk(first,second);
		printf("Result %lf %lf\n",result.Re,result.Im);
	}
}