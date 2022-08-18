#include<iostream>
#include<string>
using namespace std;

// string assignment operation
/*
-string& operator=(const char* s);	//assign a char* string to current string
-string& operator=(const string &s);	//assign a string object s to current string
-string& operator=(char c); //assign a character to current string

-string& assign(const char *s);
-string& assign(const char *s, int n);	// get front five character
-string& assign(const string &s);
-string& assign(int n, char c);
*/
void test1(){
	string s1;
	s1 = "hello xurui";
	string s2;
	s2 = s1;
	string s3;
	s3 = 'p';

	string s4;
	s4.assign("hello C++");
	string s5;
	s5.assign("hello C++", 5);
	string s6;
	s6.assign(s5);
	string s7;
	s7.assign(10, 'w');

	cout << s1 << endl << s2 << endl;
	cout << s3 << endl << s4 << endl;
	cout << s5 << endl << s6 << endl;
	cout << s7 << endl;	
}

int main(){
	test1();

	return 0;
}