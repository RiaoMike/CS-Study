#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Person{
public:
	char m_name[64];
	int m_age;
};

void test1(){
	ofstream ofs;

	ofs.open("name.txt", ios::out);

	ofs << "Name: xurui" << endl;
	ofs << "Sex: Male" << endl;
	ofs << "Age: 21" << endl;

	ofs.close();
}

void test2(){
	ifstream ifs;

	ifs.open("name.txt", ios::in);

	if (!ifs.is_open()){
		cout << "fail to open the file" << endl;
		return;
	}

	// four methods to open the files
	// 1.
	// char buf[1024];
	// while (ifs >> buf)
	// 	cout << buf << endl;
	// 2.
	// char buf[1024];
	// while (ifs.getline(buf, 1024))
	// 	cout << buf << endl;
	// 3.
	// string buf;
	// while (getline(ifs, buf))
	// 	cout << buf << endl;
	// 4.
	// char c;
	// while ((c = ifs.get()) != EOF)
	// 	cout << c;

	ifs.close();
}

void test3(){
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"rui", 21};
	ofs.write((const char*)&p, sizeof(Person));

	ofs.close();	

}
void test4(){
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open()){
		cout << "fail to open" << endl;
		return;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << p.m_name << " " << p.m_age << endl;
	ifs.close();
}

int main(){

	// test1();
	// test2();

	// test3();
	test4();

	return 0;
}