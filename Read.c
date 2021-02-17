#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"
char *nread (FILE *f, char *a){
	char *b;
	b=(char*)malloc(sizeof(char)*strlen(a)+1);
	strcpy(b,a);
	return b;
}
sight *Read(char* filename){
	FILE *f;
	char *q;
	char a[100];
	sight *head=NULL;
	f=fopen(filename, "r");
	if(f==NULL){
		return head;
	}
	while(1){
		int pom;
		sight *temp;
		q=fgets(a,100,f);
		if(q==0)break;
		temp=(sight*)malloc(sizeof(sight));
		temp->name=nread(f,a);
		fgets(a,100,f);
		temp->address=nread(f,a);
		fgets(a,100,f);
		temp->rayon=nread(f,a);
		fscanf(f,"%d",&temp->timeop);
		fscanf(f,"%d",&temp->timecl);
		temp->next=head;
		head=temp;
	}
	fclose(f);
	return head;
}
