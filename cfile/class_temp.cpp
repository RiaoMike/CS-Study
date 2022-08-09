#include<iostream>
#include<string>
using namespace std;

// *** use explicitly specify while using template

template<class NameType, class AgeType = int>
class Person{
public:
	Person(NameType s, AgeType n){
		name = s;
		age = n;
	}
	void showPerson(){
		cout << "Name: " << name << "   ";
		cout << "Age: " << age << endl;
	}
private:
	NameType name;
	AgeType age;
};

void test1(){
	// * 1. class template has no auto derivation
	// Person p1("Tom", 20);   Error!!!!
	Person<string, int> p1("Tom", 20);

	// ** 2. class template can set default args, but function template can not.
	// template<class NameType, class AgeType = int>
	Person<string> p2("Mike", 99); // default args

	// p1.showPerson();
	p2.showPerson();
}

int main(){
	test1();

	return 0;
}
