#include"Sight.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("Файл не переден \n");
		exit(1);
	}
	FILE *f;
	f = fopen(argv[1], "r");
	if(f == NULL){
		printf("Не верное имя файла\n");
                exit(1);
	}
	char* filename = argv[1];
	Menu(filename);
	return 0;
}
