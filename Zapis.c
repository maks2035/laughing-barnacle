#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"

void Zapis(sight *head, char *filename){
	FILE *f;
	f=fopen(filename, "w");
	while(head != NULL){
		fprintf(f, "%s%s%s%d\n%d",head->name,head->address,head->rayon,head->timeop,head->timecl);
		head=DeleteSight(head);
	}
	fclose(f);
}
