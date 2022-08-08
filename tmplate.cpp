#include<iostream>
using namespace std;

void swapInt(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void swapFloat(float &a, float &b){
	float tmp = a;
	a = b;
	b = tmp;
}

// function template
template<typename T>
void mySwap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

void test1(){
	int a = 10;
	int b = 20;

	// swapInt(a, b);
	// 1, auto derivation
	// mySwap(a, b);
	// 2, explicitly specify
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

// realise sort function for all array
// from big to small
// algorithm select
// testing int and char

template<class T>
void Swap(T &a, T &b){
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void Sort(T array[], int len){
	T tmp;
	for (int i = 0;i < len-1;++i){
		int max = i;
		for (int j = i+1;j < len;++j){
			if (array[j] > array[max])
				max = j;
		}
		if (max != i)
			Swap<T>(array[max], array[i]);
	}
}

template<class T>
void Display(T array[], int len){
	for (int i=0;i<len;++i){
		cout << array[i] << " ";
	}
	cout << endl;
}

void test2(){
	// testing char array
	char array1[] = "xuruinihao";
	int len1 = sizeof(array1)/sizeof(char);
	Sort<char>(array1, len1);
	Display<char>(array1, len1);

	int array2[] = {1, 3, 80, 31, 2, 908, 333, 21, 78};
	int len2 = sizeof(array2)/sizeof(int);
	Sort<int>(array2, len2);
	Display<int>(array2, len2);
}

int main(){
	test2();

	return 0;
}