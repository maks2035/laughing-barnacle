#include<stdio.h>
typedef struct sight{
	char* name;
	char* address;
	char* rayon;
	int timeop;
	int timecl;
	struct sight* next;
}sight;
char *Vvod();
sight* NewSight(sight *head);
sight* DeleteSight(sight *head);
void Redakt(sight *head);
void Zapis(sight *head, char *filename);
sight *PoiskName(char *str, sight *head);
int *PoiskRayon(char *str, sight *head);
int PoiskTime(int t, sight *head);
void Menu(char *filename);
char *nread (FILE *f, char *a);
sight *Read(char *filename);
char* fanc(int n);
