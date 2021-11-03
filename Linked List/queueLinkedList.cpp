#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *link;
};

Node *top=NULL, *n=NULL, *x=NULL;

void push(int i){
	n = new Node;
	n->data = i;
	n->link = top;
	top = n;
}

void pop(int &p){
	if(top == NULL) return;
	
	p = top->data;
	x = top;
	top = top->link;
	delete(x);
	x=NULL;
}

void tampil(){
	x = top;
	while(x!=NULL){
		cout << x->data << " ";
		x = x->link;
	}
}

int getJmlNode(){
	x = top;
	int i=0;
	while(x!=NULL){
		i++;
		x = x->link;
	}
	return i;
}

int main(){
	int x;
	push(4);
	push(5);
	push(6);
	int jmlNode = getJmlNode();
	cout << "\nJumlah Node: " << jmlNode << endl;
	
	for(int i=0; i<jmlNode; i++){
		pop(x);
		cout << x << endl;
	}
}
