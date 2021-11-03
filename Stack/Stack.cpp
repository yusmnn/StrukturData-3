#include <iostream>
#define MAX_STACK 7
using namespace std;

struct Stack{
	int elemen[MAX_STACK];
	int top;
};

void createStack(Stack &stack){
	stack.top = -1;
}

bool isEmpty(Stack stack){
	return stack.top == -1;
}

bool isFull(Stack stack){
	return stack.top == MAX_STACK-1;
}

void push(Stack &stack, int i){
	if (isFull(stack)) return;
	
	stack.top++;
	stack.elemen[stack.top] = i;
}

void pop(Stack &stack, int &i){
	if (isEmpty(stack)) return;
	
	i = stack.elemen[stack.top];
	stack.top--;
}

int main(){
	Stack s;
	int x;
	createStack(s);
//	push(s, 1);
//	push(s, 2);
//	push(s, 3);
//	push(s, 4);
//	pop(s,x);
//	push(s, 5);
//	push(s, 6);
//	pop(s,x);//
//	pop(s,x);//
//	pop(s,x);//
//	pop(s,x);//
	push(s, 7);
	push(s, 8);
//	push(s, 9);
	pop(s,x);

	cout << "Isi stack : ";
	for(int i=s.top; i>=0; i--) cout << s.elemen[i] << " ";
	cout << "\nNilai top : " << s.top << endl;
	cout << "Nilai x   : " << x << endl;
	return 0;
}
