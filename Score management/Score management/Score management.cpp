#include<iostream>
#include<string>
using namespace std;

void list();
void addstudent();
void deletestudent();
void addscores();
int find(string &name);
int studentcount=0;

struct Student{
	string name;
	string ID;
	int score;
}student[200];
 

int main(){
	int action;
	do{
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)�鿴ѧ������"<<endl;
		cout<<"2)ѡ�Σ����ѧ����"<<endl;
		cout<<"3)��ѡ��ɾ��ѧ����"<<endl;
		cout<<"4)¼��ɼ�"<<endl;
		cout<<"5)�˳�����"<<endl;
		
		cin>>action;
		switch(action){
		case(1):
			list();
			break;
		case(2):
			addstudent();
			break;
		case(3):
			deletestudent();
			break;
		case(4):
			addscores();
			break;
		case 5:
			return 0;
		default:
			cout<<"�������˴���Ĳ˵��������ѡ��"<<endl;
		}
	}while(1);
}
int find(string &name){
	int i=0;
	while(student[i].name!=name&&i<studentcount)
		i++;
	return i;
}
void addscores(){
	struct Student student;
	int n=1;
	int i;
	string name;
	while(n){
		cout<<"������Ҫ¼��ɼ���ѧ������:"<<endl;
		cin>>name;
		i=find(name);
		if(i==studentcount)
			cout<<"��ѧ��������"<<endl;
		else{
			student.name=name;
			cout<<"������ѧ��"<<endl;
			cin>>student.ID;
			cout<<"������c++�ɼ�"<<endl;
			cin>>student.score;
		}
		cout<<"�Ƿ����¼�룬����¼��������1����������0"<<endl;;
		cin>>n;
	}
}
void list(){
	cout<<"����\t"<<"ѧ��\t"<<"c++�ɼ�\t"<<endl;
	for(int i=0;i<studentcount;i++)
		cout<<student[i].name<<"\t"<<student[i].ID<<"\t"<<student[i].score<<endl;
}
void addstudent(){
	if(studentcount==200)
		cout<<"�ռ��������޷��������ѧ��"<<endl;
	else{
	cout<<"������ѧ������"<<endl;
	studentcount++;
	cout<<"�Ƿ�������ѧ������������1����������0"<<endl;
	int n;
	cin>>n;
	if(n)
		addstudent();
	}
}
void deletestudent(){
	int n=1;
	int i;
	string name;
	while(n){
		cout<<"������Ҫ¼��ɼ���ѧ������"<<endl;
		cin>>name;
		i=find(name);
		if(i==studentcount)
		cout<<"Ҫɾ����ѧ��������"<<endl;
	else{
		for(int i=0;i<(studentcount-1);i++){
		student[i]=student[i+1];
		}
		studentcount--;
	}
	}
}



	
