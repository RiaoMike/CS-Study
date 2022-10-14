#include<iostream>

using namespace std;

typedef struct Node{
	int data;
	Node *next;
}Lnode, *LinkList;

void InitList(LinkList &L){
	L = new Lnode;
	L->next = NULL;   // head node
}

void HeadInsert(LinkList &L, int num){
	Lnode *elem = new Lnode;
	elem->data = num;
	elem->next = L->next;
	L->next = elem;
}

void Display(LinkList L){
	LinkList p = L->next;
	while(p){
		cout << p->data << " " ;
		p = p->next;
	}
	cout << endl;

}

void GetLength(LinkList L){
	int count = 0;
	LinkList p = L;
	while (p->next){
		count++;
		p = p->next;
	}
	cout << "the length of the list is " << count << endl;
}

bool IsEmpty(LinkList L){
	if (L->next){
		return false;
	}
	else 
		return true;
}

void GetElem(LinkList L, int pos){
	int n = 0;
	LinkList q = L;
	while (n < pos && q->next){
		q = q->next;
		n++;
	}
	if (n != pos){
		cout << "intput error" << endl;
	}
	else {
		cout << "the number in " << pos << " is " ;
		cout << q->data << endl;
	}
}

void IndexOf(LinkList L, int num){
	int n = 1;
	LinkList p = L->next;
	while (p && p->data != num){
		p = p->next;
		n++;
	}
	if (p){
		cout << "the position of " << num << " is " ;
		cout << n << endl;
	}
	else {
		cout << "list empty or not matched" << endl;
	}
}

void Insert(LinkList &L, int pos, int num){
	int n = 1;
	LinkList p = L;
	while (p->next && n < pos){
		p = p->next;
		n++;
	}
	Lnode * elem = new Lnode;
	elem->data = num;
	elem->next = p->next;
	p->next = elem;
}

void Delete(LinkList &L, int pos){
	int n = 1;
	LinkList p = L;
	while (p->next && n < pos){
		p = p->next;
		n++;
	}
	if (p->next){
		LinkList tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
	else {
		cout << "empty or input error" << endl;
	}
}

int main(){
	LinkList L;
	InitList(L);
	HeadInsert(L, -1);
	HeadInsert(L, 21);
	HeadInsert(L, 13);
	HeadInsert(L, 24);
	HeadInsert(L, 8);

	Display(L);
	GetLength(L);
	if (!IsEmpty(L)){
		cout << "list is not empty" << endl;
	}
	else
		cout << "list is empty" << endl;

	GetElem(L, 3);
	IndexOf(L, 24);
	Insert(L, 4, 0);
	Display(L);
	Delete(L, 5);
	Display(L);

	// free
	while (L->next){
		LinkList p = L;
		L = L->next;
		delete p;
	}
	delete L;
	
	return 0;
}
