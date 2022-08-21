#include<iostream>
#define MAXSIZE 100
using namespace std;

typedef int ElementType;

typedef struct{
	ElementType *base;
	ElementType *top;
	int stacksize;
}sqstack;

class SqStack{
private:
	sqstack stack;
public:
	SqStack();
	~SqStack();
	bool IsEmpty();
	int StackLength();
	void ClearStack();
	void push(ElementType);
	ElementType pop();
};
SqStack::SqStack(){
	stack.base = new ElementType[MAXSIZE];
	if (!stack.base)
		throw("Fail to Init!!!");
	else{
		stack.top = stack.base;
		stack.stacksize = MAXSIZE;
	}

}
SqStack::~SqStack(){
	delete[] stack.base;
	stack.stacksize = 0;
	stack.base = stack.top = NULL;
	cout << "Stack has been destroyed.";
}
bool SqStack::IsEmpty(){
	if (stack.base == stack.top)
		return true;
	else
		return false;
}
int SqStack::StackLength(){
	return stack.top - stack.base;	
}
void SqStack::ClearStack(){
	stack.top = stack.base;
}
void SqStack::push(ElementType element){
	if (stack.top - stack.base == stack.stacksize)
		cerr << "Stack Full!!!" << endl;
	else{
		*stack.top = element;
		stack.top++;
	}
}
ElementType SqStack::pop(){
	if (stack.top == stack.base){
		cerr << "Stack Empty!!!" << endl;
		throw;
	}
	else{
		stack.top--;
		return *stack.top;
	}
}


int main(){
	SqStack S;
	cout << S.IsEmpty() << endl;
	S.push(34);
	S.push(21);
	cout << "Length of Stack = " << S.StackLength() << endl;
	int n = S.pop();
	cout << "n = " << n << endl;
	S.ClearStack();
	cout << S.IsEmpty() << endl;

	return 0;
}