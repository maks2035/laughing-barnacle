#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sight.h"

void Menu(char *filename){
	int k;
	int k1;
	sight *head=NULL;
	sight *dop;
	sight *dop1;
	int p;
	head=Read(filename);
	printf("программа упарвленя базы данных достопримечательностей города \n");
	do{
		printf("\n-----------------\nвыберете действие:\n"
			"добавть[1]\nудалить[2]\n"
			"вывести информацию о всех достопримечательностях[3]\n"
			"поис по названию[4]\nпоиск по районам[5]\n"
			"посмотреть, какие достопримечательности открыты в интересуюещее время[6]\n"
			"редактировать[7]\n"
			"выход[8]\n-----------------\n");
		scanf("%d", &p);
		getchar();
		switch(p){
			case 1:
				head=NewSight(head);
			break;
			case 2:
				dop=head;
				dop1=head;
				if(dop==NULL){
					printf("\n-----------------\nбаза данных пуста\n-----------------\n");
					break;
				}
				printf("\nвведите название достопримечательности:");
				dop=PoiskName(Vvod(), dop);
				if(dop==NULL){
					printf("\n-----------------\nдостопримечательность не найдена\n-----------------\n");
					break;
				}
				if(dop==head)
					head=DeleteSight(dop);
				else{
					while(1){
						if(dop1->next==dop)
							break;
						else dop1=dop1->next;
					}
					dop1->next=DeleteSight(dop);
				}
			break;
			case 3:
				dop=head;
		               if(dop==NULL){
		                        printf("\n-----------------\nбаза данных пуста\n-----------------\n");
		                        break;
		               }
				while(dop!=NULL){
					printf("-----------------"
					"\nназвание:%sадрес:%sрайон:%sвремя работы: %d:00-%d:00\n"
					"-----------------",
					dop->name, dop->address, dop->rayon, dop->timeop, dop->timecl);
					dop=dop->next;
				}
			break;
			case 4:
				dop=head;
		               if(dop==NULL){
		                        printf("\n-----------------\nбаза данных пуста\n-----------------\n");
		                        break;
		               }
		               printf("введите название достопримечательности:");
		               dop=PoiskName(Vvod(), dop);
		               if(dop==NULL){
		                        printf("\n-----------------\nдостопримечательность не найдена\n-----------------\n");
		                        break;
		               }
				printf("\n-----------------\nназвание:%s\nадрес:%s\nрайон:%s\nвремя работы: %d:00-%d:00\n-----------------\n",
		                        dop->name, dop->address, dop->rayon, dop->timeop, dop->timecl);
			break;
			case 5:
				dop=head;
		               if(dop==NULL){
		                        printf("\n-----------------\nбаза данных пуста\n-----------------\n");
		                        break;
		               }
		               printf("введите район:");
		               PoiskRayon(Vvod(), dop);
			break;
			case 6:
				dop=head;
		               if(dop==NULL){
		                        printf("\n-----------------\nбаза данных пуста\n-----------------\n");
		                        break;
		               }
		               printf("введите интересующее время(целое число от 0 до 24):");
				scanf("%d", &k1);
				if((k1>=0) && (k1<=24)){
		               	PoiskTime(k1, dop);
		               }else printf("\n-----------------\nуказано неверное время\n-----------------\n");
			break;
			case 7:
				dop=head;
				if(dop==NULL){
					printf("\n-----------------\nбаза данных пуста\n-----------------\n");
					break;	
				}
				printf("введите название достопримечательности:");
				dop=PoiskName(Vvod(), dop);
				if(dop==NULL){
					printf("\n-----------------\nдостопримечательность не найдена\n-----------------\n");
					break;	
				}
				Redakt(dop);
			break;
			case 8:
				Zapis(head, filename);
				printf("\n-----------------\nзавершение работы программы\n-----------------\n");
			break;
			default:
				printf("\n-----------------\nкоманды под данным номером нет\n-----------------\n");
			break;
		}
	}while(p!=8);
}
