#include<iostream>
#include<string>
using namespace std;

// 1. find
void test1(){
	string s1 = "abcdefgde";

	int pos1 = s1.find("de");
	int pos2 = s1.find("df");	
	cout << "pos1 = " << pos1 << endl;
	cout << "pos2 = " << pos2 << endl;

	// rfind
	int pos = s1.rfind("de");
	cout << "rfind pos = " << pos << endl;
	// difference between rfind and find
	// rfind from right to left, while find from left to right
}

// 2. replace
void test2(){
	string s2 = "abcdefg";

	s2.replace(1, 3, "1111");
	cout << "s2 = " << s2 << endl;
}

// 3. string compare
void test3(){
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.compare(s2)==0)
		cout << "s1 == s2" << endl;
	else if (s1.compare(s2) > 0)
		cout << "s1 > s2" << endl;
	else
		cout << "s1 < s2" << endl;
}

int main(){
	// test1();

	// test2();
	test3();
	return 0;
}