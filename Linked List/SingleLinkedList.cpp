#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void buatNodeBaru(int i){
	n = new Node;
	n->data = i;
	tail = n;
	head = n;
	tail->next = NULL;
}

void tambahDiBelakang(int i){
	n = new Node;
	n->data = i;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiDepan(int i){
	n = new Node;
	n->data = i;
	n->next = head;
	head = n;
}

void tambahDiTengah(int i, int j){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = i;
	n->next = x->next;
	x->next = n;
}

void hapusDiDepan(){
	x = head;
	head = head->next;
	delete(x);
	x = NULL;
}

void hapusDiBelakang(int i){
	x = head;
	while(x->next != tail) x = x->next;
	tail = x;
	delete(x->next);
	tail->next = NULL;
}

void hapusDiTengah(int i){
	Node *temp=NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete(x);
	x = NULL;
}

void tampilData(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}

int main(){
	buatNodeBaru(10);
	tambahDiBelakang(20);
	tambahDiBelakang(30);
	tambahDiBelakang(40);
	hapusDiTengah(30);
	tambahDiDepan(50);
	tambahDiDepan(60);
	tambahDiTengah(70, 10);
	
	tampilData();
}
