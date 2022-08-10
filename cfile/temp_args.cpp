#include<iostream>
using namespace std;


// class template object to be function args

template<class T1, class T2>
class Person{
public:
	Person(T1 s, T2 n){
		name = s;
		age = n;
	}
	void showPerson(){
		cout << "Person show here" << endl;
		cout << name << " " << age << endl;
	}
	T1 name;
	T2 age;
};

// 1. specify incoming type
void printPerson1(Person<string, int> &p){
	p.showPerson();
}

void test1(){
	Person<string, int> p("wukong", 99);	
	printPerson1(p);
}

// 2. make args to a template
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p){
	p.showPerson();
	cout << "type of T1 is: " << typeid(T1).name() << endl;
	cout << "type of T2 is: " << typeid(T2).name() << endl;
}

void test2(){
	Person<string, int> p("bajie", 66);
	// auto derivation
	printPerson2(p);
	// printPerson2<string, int> (p); // explicitly specify
}

// 3. make the hole class(like Person<string, int>) to a template
template<class T>
void printPerson3(T &p){
	p.showPerson();
	cout << "the type of T is: " << typeid(T).name() << endl;
}

void test3(){
	Person<string, int> p("tangseng", 30);

	printPerson3<Person<string, int>>(p);
	// also auto derivation
	// printPerson3(p);
}

int main(){
	// test1();
	// test2();
	test3();

	return 0;
}