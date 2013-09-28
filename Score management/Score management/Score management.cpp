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
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)查看学生名单"<<endl;
		cout<<"2)选课（添加学生）"<<endl;
		cout<<"3)退选（删除学生）"<<endl;
		cout<<"4)录入成绩"<<endl;
		cout<<"5)退出程序"<<endl;
		
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
			cout<<"您输入了错误的菜单项，请重新选择！"<<endl;
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
		cout<<"请输入要录入成绩的学生姓名:"<<endl;
		cin>>name;
		i=find(name);
		if(i==studentcount)
			cout<<"该学生不存在"<<endl;
		else{
			student.name=name;
			cout<<"请输入学号"<<endl;
			cin>>student.ID;
			cout<<"请输入c++成绩"<<endl;
			cin>>student.score;
		}
		cout<<"是否继续录入，继续录入请输入1，否则输入0"<<endl;;
		cin>>n;
	}
}
void list(){
	cout<<"姓名\t"<<"学号\t"<<"c++成绩\t"<<endl;
	for(int i=0;i<studentcount;i++)
		cout<<student[i].name<<"\t"<<student[i].ID<<"\t"<<student[i].score<<endl;
}
void addstudent(){
	if(studentcount==200)
		cout<<"空间已满，无法继续添加学生"<<endl;
	else{
	cout<<"请输入学生姓名"<<endl;
	studentcount++;
	cout<<"是否继续添加学生，是请输入1，否则输入0"<<endl;
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
		cout<<"请输入要录入成绩的学生姓名"<<endl;
		cin>>name;
		i=find(name);
		if(i==studentcount)
		cout<<"要删除的学生不存在"<<endl;
	else{
		for(int i=0;i<(studentcount-1);i++){
		student[i]=student[i+1];
		}
		studentcount--;
	}
	}
}



	
