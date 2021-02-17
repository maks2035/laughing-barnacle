#include"Sight.h"
#include<stdlib.h>
#include<stdio.h>

sight* DeleteSight(sight* head){
	sight* dopoln;
	dopoln = head->next;
	free(head->name);
	free(head->address);
	free(head->rayon);
	free(head);
	return dopoln;
}
