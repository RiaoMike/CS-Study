#include<iostream>
#include<string>
using namespace std;

typedef struct{
	string name;
	double score;
}ElementType;
typedef struct Lnode{
	ElementType element;
	Lnode * next;
}Lnode,* Llist;

// wojiaoxujiarui
class List{
private:
	Llist L;
public:
	List();
	List(int, bool);
	~List();
	int isEmptyList();
	void ClearList();
	void Append_back(const ElementType &);
	int GetLength();
	ElementType GetElement(int);
	void Display();
	int Index(const ElementType &);
	void Insert(int, const ElementType &);
	void Delete(int);
};

List::List(){
	L = new Lnode;
	L -> next = NULL;
	cout << "list has been created." << endl;
}
List::List(int n, bool rever = false){
	if (n<0){
		cout << "Invalid Input! Default to Empty list." << endl;
		n = 0;
	}
	L = new Lnode;
	L->next = NULL;
	if (n)
		cout << "Please enter " << n << " element: " << endl;
	if (!rever){
		Llist p = L;
		for (int i=0;i<n;++i){
			Llist new_node = new Lnode;
			cin >> new_node->element.name >> new_node->element.score;
			new_node->next = NULL;
			p->next = new_node;
			p = new_node;
		}
		cout << "list has been created." << endl;
	}
	else{
		for (int i=0;i<n;++i){
			Llist new_node = new Lnode;
			cin >> new_node->element.name >> new_node->element.score;
			new_node->next = L->next;
			L->next = new_node;
		}
		cout << "list has been created." << endl;
	}
}
List::~List(){
	Llist p;
	while (L){
		p = L;
		L = L->next;
		delete p;
	}
	cout << "list has been destroyed." << endl;
}
int List::isEmptyList(){
	if (L->next == NULL)
		return 1;
	else
		return 0;
}
void List::ClearList(){
	Llist p,q;
	p = L->next;
	while(p){
		q = p;
		p = p->next;
		delete q;
	}
	L->next = NULL;
}
void List::Append_back(const ElementType &a){
	Llist new_node = new Lnode;
	new_node->element = a;
	new_node->next = NULL;
	Llist p = L;
	while(p->next)
		p = p->next;
	p->next = new_node;
}
int List::GetLength(){
	Llist p = L->next;
	int i = 0;
	while (p){
		i++;
		p = p->next;
	}
	return i;
}
ElementType List::GetElement(int n){
	Llist p = L->next;
	int i = 1;
	while (p && i<n){
		p = p->next;
		i++;
	}
	if (!p || i>n){
		cout << "Not Exists!!!" << endl;
		throw "ERROR";
	}
	return p->element;
}
void List::Display(){
	Llist p = L->next;
	while (p){
		cout << "Name: " << p->element.name;
		cout << " Score: " << p->element.score << endl;
		p = p->next;
	}
}
int List::Index(const ElementType &a){
	Llist p = L->next;
	int i = 1;
	while (p && (p->element.name!=a.name || p->element.score!=a.score)){
		i++;
		p = p->next;
	}
	if (!p){
		cout << "Not matched!" << endl;
		return 0;
	}
	else
		return i;
}
void List::Insert(int n, const ElementType &a){
	Llist p = L;
	int i = 1;
	while (p->next && i<n){
		p = p->next;
		i++;
	}
	if (i!=n){
		cout << "Invalid Input!" << endl;
	}
	else{
		Llist x = new Lnode;
		x->element = a;
		x->next = p->next;
		p->next = x;
	}
}
void List::Delete(int n){
	Llist p = L;
	int i = 1;
	while (p->next && i<n){
		p = p->next;
		i++;
	}
	if (!p->next || i>n){
		cout << "Invalid Input or Empty list!" << endl;
	}
	else{
		Llist q = p->next;
		p->next = q->next;
		// also p->next = p->next->next;
		delete q;
	}
}

int main(){
	List list;
	cout << list.isEmptyList() << endl;
	ElementType a[2] = {"xurui",97.3,"wushiqi",91.2};
	ElementType b = {"xuhao", 62.5};
	list.Append_back(a[0]);
	list.Append_back(a[1]);
	cout << list.isEmptyList() << endl;
	cout << "L has length of " << list.GetLength() << endl;
	list.Display();
	cout << "index of a[1] is: " << list.Index(a[1]) << endl;
	cout << "index of b is: " << list.Index(b) << endl;
	//testing
	cout << "-----------Testing--------------(for insert)" << endl;
	list.ClearList();
	list.Insert(0,b);
	list.Insert(1,b);
	list.Display();
	list.Insert(4,b);
	list.Insert(2,a[0]);
	list.Display();
	cout << "insert again." << endl;
	list.Insert(2,a[1]);
	list.Display();
	cout << "-----------Testing--------------(for delete)" << endl;
	list.Delete(0);
	list.Delete(5);
	cout << "now delete the second node" << endl;
	list.Delete(2);
	list.Display();
	cout << "-----------Testing--------------(for contributor function)" << endl;
	List new_list(-2);
	List another_list(3);
	another_list.Display();
	List reverse_list(2,true);
	reverse_list.Display();

	return 0;
}
