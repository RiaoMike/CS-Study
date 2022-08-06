#include<iostream>
#include<vector>
int main(){
	using namespace std;
	vector<int> rui{1,2,3,4,5};
	vector<int>::iterator iter1 = rui.begin(),
	iter2 = rui.end()-1;
	cout << iter2 - iter1 << endl;
	cout << "hello ,xurui";
	return 0;
}