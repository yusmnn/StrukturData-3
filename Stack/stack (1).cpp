#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *link;
};

Node *top = NULL, *n = NULL, *x = NULL;
int jumlah = 0, nilai_pop;

void push(int i){
    n = new Node;
    n->data = i;
    n->link = top;
    top = n;
    jumlah = jumlah + 1;
}

void pop(){
    x = top;
    x = x->link;
    nilai_pop = top->data;
    delete top;
    top = x;
    jumlah = jumlah - 1;
}

void tampilkan(){
    x= top;
    while (x != NULL){
        cout << x->data << " ";
        x= x->link;
    }
}

int main(){
    push(4);
    push(5);
    push(6);

    tampilkan();
}
