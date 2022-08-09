#include<iostream>
#include<string>

using namespace std;

class Person{
public:
	Person(string, int);
	bool operator==(Person &p);
	string name;
	int age;
};
Person::Person(string s, int n){
	name = s;
	age = n;
}
bool Person::operator==(Person &p){
	if (name == p.name && age == p.age)
		return true;
	else
		return false;
}

template<class T>
bool myCompare(T &a, T &b){
	if (a == b)
		return true;
	else
		return false;
}
// 2.function specify (just like open back door for Person)
bool myCompare(Person &p1, Person &p2){
	if (p1.name == p2.name && p1.age == p2.age)
		return true;
	else
		return false;
}

void test1(){
	int a = 10;
	int b = 20;

	bool ret = myCompare<int>(a, b);
	if (ret)
		cout << "a == b" << endl;
	else
		cout << "a != b" << endl;
}

void test2(){
	Person p1("Tom", 20);
	Person p2("Mike", 20);

	// there are two methods to solve the problem that 
	// "==" in function myCompare can't take effect for Person
	// 1. define operator "==" in class Person(operator overloading)
	// bool ret = myCompare<Person>(p1, p2);
	// 2. function specify( see the second myCompare)
	bool ret = myCompare(p1, p2); // call the second myCompare

	if (ret)
		cout << "p1 == p2" << endl;
	else
		cout << "p1 != p2" << endl;
}

int main(){

	// test1();
	test2();

	return 0;
}