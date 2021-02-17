#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"
int *PoiskRayon(char *str, sight *head){
	int i = 0;
	while(head !=NULL){
                if(!strcmp(head->rayon,str)){
                	i++;
                       printf("\n-----------------\nназвание:%sадрес:%sрайон:%sвремя открытия:%d:00\nвремя закрытия:%d:00\n-----------------\n", head->name, head->address, head->rayon, head->timeop, head->timecl);
                       head=head->next;
                }else head=head->next;
        }
        if(i==0)
        	printf("\n-----------------\nдостопримечательность не найдена\n-----------------\n");
        return 0;
}
