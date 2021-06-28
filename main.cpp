#include"sight.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]){
	if(argc <= 1){
		cout << "Файл не переден\n";
		exit(0);
	}
	ifstream f(argv[1]);
	if(!f.is_open()){
		cout << "Не верное имя файла\n";
        	exit(0);
	}
	f.close();
	List list;
	list.read(argv[1]);
	int p;
	cout<<"программа упарвленя базы данных достопримечательностей города \n";
	do{
		cout<<"\n-----------------\nвыберете действие:\n"
			"добавть[1]\nудалить[2]\n"
			"вывести информацию о всех достопримечательностях[3]\n"
			"поис по названию[4]\nпоиск по районам[5]\n"
			"посмотреть, какие достопримечательности открыты в интересуюещее время[6]\n"
			"редактировать[7]\n"
			"выход[8]\n-----------------\n";
		cin>>p;
		getchar();
		switch(p){
			case 1:{
				sight help;
				help.set_name();
				help.set_address();
				help.set_rayon();
				help.set_time();
				list.dob_sight(help);
			}
			break;
			case 2:{
				list.delete_sight(list.poisk_name());
			}
			break;
			case 3:{
				list.print_list();
			}break;
			case 4:{
				sight* help = list.poisk_name();
				if(help != nullptr){
					cout << *help;
				}else{
					cout<<"ненайдено\n";
				}
			}
			break;
			case 5:{
				sight* help = list.poisk_rayon();
				if(help == nullptr){
					cout<<"ненайдено\n";
				}
			}
			break;
			case 6:{
				int k;
				cout<<"введите время ";
				cin >> k;
				sight* help = list.poisk_time(k);
				if(help == nullptr){
					cout<<"ненайдено\n";
				}
			}
			break;
			case 7:{
				sight* help = list.poisk_name();
				if(help != nullptr){
					list.redakt(help);
				}else{
					cout<<"ненайдено\n";
				}
			}
			case 8:{
				list.zapis(argv[1]);
				cout<<"\n-----------------\nзавершение работы программы\n-----------------\n";
			}
			break;
			default:{
				cout<<"\n-----------------\nкоманды под данным номером нет\n-----------------\n";
			}
			break;
		}
	}while(p!=8);
	return 0;
}
