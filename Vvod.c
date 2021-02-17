#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"
char *Vvod(){
	char buffer[128];
	char *a;
	fgets(buffer,128,stdin);
	a=(char*)malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(a,buffer);
	return a;
}
