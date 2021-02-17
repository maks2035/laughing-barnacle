#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"
void Redakt(sight *head){
	int x;
	do{
		printf("выберете, что хотите редактировать\n"
		"название.[1]\n адрес.[2]\n район.[3]\n время.[4]\n"
		"выход из режима редактирования.[5]\n");
		scanf("%d", &x);
		char help[2];
		int i;
		switch(x){
			case 1:
				getchar();
				printf("\nвведите название достопримечательности:");
				free(head->name);
				printf("\n");
				head->name=Vvod();
			break;
			case 2:
				getchar();
				printf("введите адрес:");
				free(head->address);
				printf("\n");
				head->address=Vvod();
			break;
			case 3:
				getchar();
				printf("введите район:");
				free(head->rayon);
                               printf("\n");
                               head->rayon=Vvod();
			break;
			case 4:
				getchar();
				do{
					i = 0;
					printf("введите время открытия и время закрытия:");
					scanf("%d %d",&head->timeop ,&head->timecl);
					printf("\n");
				}while(head->timeop >= head->timecl);
			break;
		}
	}while(x != 5);
}
