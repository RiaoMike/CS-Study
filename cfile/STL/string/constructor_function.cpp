#include<iostream>
#include<string>
using namespace std;

// the construtor function of string

/*
-string();	//create a empty string;
-string(const char* s);	//create a string with a character string s;
-string(const string& str);	//create a string with a string object;
-string(int n, char c);	//initalize a string with n characters c;
*/

void test1(){
	string s1; //default construction
	
	const char* ch = "hello, xurui";
	string s2(ch);

	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(5, 'q');
	cout << "s4 = " << s4 << endl;
}

int main(){
	test1();

	return 0;
}