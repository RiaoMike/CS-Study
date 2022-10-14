#include<iostream>
#define MAXSIZE 50

using namespace std;
typedef struct{
	int *elem;
	int length;
}SqList;

void InitList(SqList &L){
	L.elem = new int[MAXSIZE];
	L.length = 0;
}

void Push(SqList &L, int n){
	L.elem[L.length] = n;
	L.length++;
}

void Display(SqList L){
	for (int i = 0;i < L.length; ++i){
		cout << L.elem[i] << " " ;
	}
	cout << endl;
}

void GetLength(SqList L){
	cout << "length is " << L.length << endl;
}

bool IsEmpty(SqList L){
	return (L.length == 0);
}

void GetElem(SqList L, int p){
	if (p > L.length || p < 1){
		cout << "input error" << endl;
	}
	else {
		cout << "the number of the position " << p << " is " ;
		cout << L.elem[p-1] << endl;
	}
}

void IndexOf(SqList L, int e){
	int index = 0;
	while (index < L.length && L.elem[index] != e){
		index++;
	}
	if (index == L.length){
		cout << "Not found" << endl;
	}
	else {
		cout << "the index of " << e << " is " << index + 1;
		cout << endl;
	}
}

// p position ; num (the number that inserted)
void Insert(SqList &L, int p, int num){
	if (p <= 0 || p > L.length + 1){
		cout << "position error" << endl;
	}
	else { 
		for (int i = L.length-1; i >= p-1 ;i--){
			L.elem[i+1] = L.elem[i];
		}
		L.elem[p-1] = num;
		L.length++;
	}
}

void Delete(SqList &L, int p){
	if (p <= 0 || p > L.length){
		cout << "input error" << endl;
	}
	else {
		for (int i = p; i < L.length; ++i){
			L.elem[i-1] = L.elem[i];
		}
		L.length--;
	}
}

void Destroy(SqList &L){
	L.length = 0;
	delete [] L.elem;
}

int main(){
	SqList L;
	InitList(L);
	Push(L, -1);
	Push(L, 21);
	Push(L, 13);
	Push(L, 24);
	Push(L, 8);

	Display(L);
	GetLength(L);
	if (IsEmpty(L)){
		cout << "list is empty" << endl;
	}
	else cout << "list is not empty" << endl;

	GetElem(L, 3);
	IndexOf(L, 24);
	Insert(L, 4, 0);
	Display(L);
	Delete(L, 5);
	Display(L);

	Destroy(L);
	return 0;
}
