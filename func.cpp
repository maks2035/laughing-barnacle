#include"sight.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

void List::redakt(sight* h){
	int x;
		do{
		cout<<"\n-----------------\nвыберете, что хотите редактировать\n"
		"название.[1]\nадрес.[2]\nрайон.[3]\nвремя.[4]\n"
		"выход из режима редактирования.[5]\n-----------------\n";
		cin>>x;
		int i;
		switch(x){
			case 1:
				h->set_name();
			break;
			case 2:
				h->set_address();
			break;
			case 3:
				h->set_rayon();
			break;
			case 4:
				h->set_time();
			break;
		}
	}while(x != 5);
}
sight* List::poisk_name(){
	sight* help=nullptr; 
	sight* tmp=nullptr;
	tmp = head;
	string n;
	cout<<"введите название ";
	cin >> n;
	while (tmp != nullptr) {
		if (tmp->name() == n) {
			help = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return help;
}
sight* List::poisk_rayon(){
	sight* help = nullptr;
	sight* tmp;
	tmp = head;
	string n;
	cout<<"введите район ";
	cin >> n;
	while (tmp != nullptr) {
		if (tmp->rayon() == n) {
			help = tmp;
			cout << *help;
		}
		tmp = tmp->next;
	}
	return help;
}
sight* List::poisk_time(int k){
	sight* help = nullptr;
	sight* tmp;
	tmp = head;
	int i = 0;
	while (tmp != nullptr) {
		if (tmp->timeop() <= k && tmp->timecl() >= k) {
			help = tmp;
			cout << *help;
		}
		tmp = tmp->next;
	}
	return help;
}
void List::dob_sight(sight h){
	sight* tmp = new sight(h);
	tmp->next = head;
	tmp->up = nullptr;
	if(head){
		head->up=tmp;
	}
	head = tmp;
}
void List::print_list(){
	sight* tmp;
	tmp = head;
	while(tmp != nullptr){
		cout << *tmp;
		tmp=tmp->next;
	}
}
void List::read(char* filename){
	string name, add, ray, op, cl;
	ifstream in(filename);
	while(1){
		if(getline(in,name) && getline(in,add) && getline(in,ray) && getline(in,op) && getline(in,cl)){
			sight help(name, add, ray, stoi(op),stoi(cl));
			this->dob_sight(help);
		}else{
			break;
		}
	}
	in.close();
}
void List::zapis(char* filename){
	sight* tmp = head;
	ofstream out(filename);
	while(tmp != nullptr){
		out<<tmp->name()<<"\n"<<tmp->address()<<"\n"<<tmp->rayon()<<"\n"<<tmp->timeop()<<"\n"<<tmp->timecl()<<"\n";
		tmp=tmp->next;
	}
	out.close();
}	
void List::delete_sight(sight* a){
	sight* help = a;
	if (!help)
		return;
	if (help->up == nullptr){
		if (head->next){
			head = help->next;
			help->next->up = nullptr;
		}else{
			head = nullptr;
			return;
		}
	}else{
		if (help->up) 
			help->up->next = help->next;
		if (help->next) 
			help->next->up = help->up;
	}	
	return;
}
