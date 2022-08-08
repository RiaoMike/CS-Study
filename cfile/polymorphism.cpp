#include<iostream>
using namespace std;

class Animal{
public:
	virtual void speak(){
		cout << "Animal is speaking." << endl;
	}
};

class Cat :public Animal{
public:
	void speak(){
		cout << "Cat is speaking." << endl;
	}
};
class Dog :public Animal{
public:
	void speak(){
		cout << "Dog is speaking." << endl;
	}
};

void Dospeak(Animal &animal){
	animal.speak();
}
void test1(){
	Cat cat;
	Dospeak(cat);
	Dog dog;
	Dospeak(dog);
}

int main(){
	test1();
	return 0;
}