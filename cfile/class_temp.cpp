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

//***************another thing************************
// the creating time of member function in a class template
class Person1{
public:
	void showPerson1(){
		cout << "Person1 show." << endl;
	}
};
class Person2{
public:
	void showPerson2(){
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyPerson{
public:
	T obj;
	
	void func1(){
		// compile won't call error. 
		// ** function in class template create while specify the class **
		obj.showPerson1();
	}
	// void func2(){
	// 	obj.showPerosn2();
	// }
};

void test2(){
	cout << "everything is ok" << endl;

	MyPerson<Person1> m;
	// specify the MyPerson class and func2() can't appear
	m.func1();
	// m.func2();
	cout << "everything is also ok" << endl;

}

int main(){
	// test1();
	test2();

	return 0;
}
