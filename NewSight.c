#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"Sight.h"
sight* NewSight(sight* head){
	char* help;
	sight* nsight=(sight*)malloc(sizeof(sight));
	for(int i=0; i<1;){
		printf("введите название:\n");
		help=Vvod();
		if(help != NULL){
			i++;
			nsight->name=help;
		}
	}
	for(int i=0; i<1;){
		printf("введите адрес:\n");
		help=Vvod();
		if(help != NULL){
			i++;
			nsight->address=help;
		}
	}
	for(int i=0; i<1;){
		printf("введите район:\n");
		help=Vvod();
		if(help != NULL){
			i++;
			nsight->rayon=help;
		}
	}
	do{
		printf("введите время открытия и время закрытия:");
		scanf("%d %d", &nsight->timeop,&nsight->timecl);
	}while(nsight->timeop >= nsight->timecl);
	nsight->next=head;
	return nsight;
}
