#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *link;
};

Node *top = NULL, *n = NULL, *x = NULL;
int jml = 0;

void push(int i){
	n = new Node;
	n -> data = i;
	n -> link = top;
	top = n;
	jml = jml + 1;
}

void pop(){
	int nilai_pop;
	x = top;
	x = x -> link;
	nilai_pop = top -> data;
	delete n;
	top = x;
	jml = jml - 1;
}

void tampilisistack(){
	x = top;
	while(x != NULL){
		cout << " " << (x -> data);
		x = x -> link;
	}
}

int main() {
	
	push(4);
	push(5);
	push(6);
	
	pop();
	
	tampilisistack();

    return 0;
}
