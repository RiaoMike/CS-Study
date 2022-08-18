#include<iostream>
#include<string>
using namespace std;

//string concatenate
/*
-string& operator+=(const char* str);
-string& operator+=(const char c);
-string& operator+=(const string &str);

-string& append(const char *s);
-string& append(const char *s, int n);  //cat with front n characters
-stirng& append(const string &s);
-string& append(const string &s, int pos, int n); //cat with n characters of s begin with the pos position

*/

void test1(){
	string s1;
	s1 = "hello, xurui";
	cout << "Init s1 = " << s1 << endl;
	s1 += " Love Math";
	cout << "Step1 s1 = " << s1 << endl;
	s1 += 'p';
	cout << "Step2 s2 = " << s1 << endl;
	string s2 = ". What's your name? ";
	s1 += s2;
	cout << "Step3 s1 = " << s1 << endl;

	string s3 = "git";
	cout << "Init s3 = " << s3 << endl;
	s3.append(" is useful");
	cout << "Step1 s3 = " << s3 << endl;
	s3.append(" and good", 6);
	cout << "Step2 s3 = " << s3 << endl;
	s3.append(s2);
	cout << "Step3 s3 = " << s3 << endl;
	s3.append(s2, 9, 4);
	cout << "Finally s3 = " << s3 << endl;
}


int main(){
	test1();	
	return 0;
}