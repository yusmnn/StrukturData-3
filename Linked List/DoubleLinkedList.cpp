#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void buatNodeBaru(int i){
	n = new Node;
	n->data = i;
	n->prev = NULL;
	head = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiBelakang(int i){
	n = new Node;
	n->data = i;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiDepan(int i){
	n = new Node;
	n->data = i;
	n->next = head;
	head->prev = n;
	n->prev = NULL;
	head = n;
}

void tambahDiTengah(int i, int j){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = i;
	n->next = x->next;
	x->next = n;
	n->prev = x;
	x = n->next;
	x->prev = n;
}

void tambahData(int i){
	if(head == NULL)
		buatNodeBaru(i);
	else
		tambahDiBelakang(i);
}

void tampilDariDepan(){
	x = head;
	while(x!=NULL){
		cout << x->data << " ";
		x = x->next;
	}
}

void tampilDariBelakang(){
	x = tail;
	while(x!=NULL){
		cout << x->data << " ";
		x = x->prev;
	}
}

void hapusDiDepan(){
	x = head;
	head = head->next;
	delete(x);
	x = NULL;
	head->prev = NULL;
}

void hapusDiBelakang(){
	x = tail;
	tail = tail->prev;
	delete(x);
	x = NULL;
	tail->next = NULL;
}

void hapusDiTengah(int i){
	Node *temp = NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	temp = x->next;
	temp->prev = x->prev;
	delete(x);
	x = NULL;
}

bool cariData(int i){
	x = head;
	while(x!=NULL){
		if (i == x->data) return true;
		x = x->next;
	}
	return false;
}

void hapusData(int i){
	if(!cariData(i)) return;
	
	if (i == head->data)
		hapusDiDepan();
	else if (i == tail->data)
		hapusDiBelakang();
	else
		hapusDiTengah(i);
}

int main(){
	tambahData(1);
	tambahData(2);
	tambahData(3);
	tambahData(13);
	hapusData(13);
	tampilDariDepan();
	
}
