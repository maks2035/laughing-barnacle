#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

class sight{
private:
	string _name;
	string _address;
	string _rayon;
	int _timeop;
	int _timecl;
public:
	sight* next;
	sight* up;
	sight(){
		next = nullptr;
		up = nullptr;
	}
	sight(string n, string add, string ray, int op, int cl){
		cout<<"cacac";
		_name = n;
		_address = add;
		_rayon = ray;
		_timeop = op;
		_timecl = cl;
		next = nullptr;
		up = nullptr;
		
	}
	~sight(){
		
	}
	string name(){
		return _name;
	}
	string address(){
		return _address;
	}
	string rayon(){
		return _rayon;
	}
	int timeop(){
		return _timeop;
	}
	int timecl(){
		return _timecl;
	}
	void set_name(){
		string n;
		int i = 0;
		while(i != 1){
			cout<<"введите название ";
			cin>>n;
			if(n != ""){
				_name = n;
				i++;
			}else{
				cout <<"недопустимое значение. пустое имя";
			}
		}
	}
	void set_address(){
		string add;
		int i = 0;
		while(i != 1){
			cout<<"введите адрес ";
			cin>>add;
			if(add != ""){
				_address = add;
				i++;
			}else{
				cout <<"недопустимое значение. пустой адрес";
			}
		}
	}
	void set_rayon(){
		string ray;
		int i = 0;
		while(i != 1){
			cout<<"введите район ";
			cin>>ray;
			if(ray != ""){
				_rayon = ray;
				i++;
			}else{
				cout <<"недопустимое значение. пустой район";
			}
		}
	}
	void set_time(){
		int op, cl;
		int i = 0;
		while(i != 1){
			cout<<"введите время открытия ";
			cin>>op;
			cout<<"введите время закрытия ";
			cin>>cl;
			if(op < cl && op >= 0 && cl <= 24){	
				_timeop = op;
				_timecl = cl;
				 i++;
			}else{
				cout <<"недопустимое значение передаваемого времени";
			}
		}
	}
	friend ostream& operator<< (ostream& out,const sight& a){
		out <<"\n-----------------\n";
		out << a._name<<endl;
		out << a._rayon<<endl;
		out << a._address<<endl;
		out << a._timeop << ":00-" << a._timecl << ":00"<<endl;
		out <<"-----------------\n";
		return out;
	}
	friend istream& operator >> (istream& in, sight& a){
		cout <<"введите название ";
		in >> a._name;
		cout <<"введите адрес ";
		in >> a._address;
		cout<<"введите район ";
		in >> a._rayon;
		cout <<"введите время открытия ";
		in >> a._timeop;
		cout <<"введите закрытия ";
		in >> a._timecl;
		cout <<"введите закрытия ";
		return in;
	}
};
class List{
public:
	sight* head;
	List(){
		head = nullptr;
	}
	List(sight a){
		sight* tmp = head;
	}
	~List(){
		sight* tmp;
		tmp = head;
		while(tmp != nullptr){
			sight* t = tmp;
			tmp= t->next;
		delete t;
		}
	}
	void redakt(sight* h);
	sight* poisk_name();
	sight* poisk_rayon();
	sight* poisk_time(int k);
	void dob_sight(sight h);
	void print_list();
	void read(char* filename);
	void zapis(char* filename);	
	void delete_sight(sight* a);
};
