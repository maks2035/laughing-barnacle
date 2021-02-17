#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"
sight *PoiskName(char *str, sight *head){
	while(head !=NULL){
		if(!strcmp(head->name,str))
			break;
		else head=head->next;
	}
	return head;
}
