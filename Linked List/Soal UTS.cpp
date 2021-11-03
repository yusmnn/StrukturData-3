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
	while(x->data != j) x=x->next;
	n = new Node;
	n->data = i;
	n->next = x->next;
	x->next = n;
	n->prev = x;
	x = n->next;
	x->prev = n;
}

void tambahData(int i){
	if (head==NULL)
		buatNodeBaru(i);
	else
		tambahDiBelakang(i);
}

void hapusDiDepan(){
	x = head;
	head = x->next;
	head->prev = NULL;
	delete(x);
	x = NULL;
}

void hapusDiBelakang(){
	x = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete(x);
	x = NULL;
}

void hapusDiTengah(int i){
	n = NULL;
	x = head;
	while(x->data != i){
		n = x;
		x = x->next;
	}
	n->next = x->next;
	x = x->next;
	delete(x->prev);
	x->prev = n;
		
}

void tampilDariDepan(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}

void tampilDariBelakang(){
	x = tail;
	while(x != NULL){
		cout << x->data << " ";
		x = x->prev;
	}
}

bool cariData(int i){
	x = head;
	while(x != NULL){
		if (i == x->data) return true;
		x = x->next;
	}
	return false;
}

void hapusData(int i){
	if (!cariData(i) || head == NULL) return;
	
	if (i == head->data)
		hapusDiDepan();
	else if (i == tail->data)
		hapusDiBelakang();
	else
		hapusDiTengah(i);
}

int getJmlNode(){
	Node *temp;
	int n = 0;
	temp = head;
	while(temp != NULL){
		temp = temp -> next;
		n++; 
	}
	return n;
}

int main(){
	tambahData(10);
	tambahData(20);
	tambahData(30);
	tambahData(40);
	tambahData(50);
	tambahData(60);

	cout << "Jumlah node: " << getJmlNode() << endl; //output ->  Jumlah node: 6
}
