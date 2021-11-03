#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *n=NULL, *tail=NULL, *head=NULL, *x=NULL;

//prototype
bool isEmpty();
void nodeBaru(int i);
void tambahDepan(int i);
void tambahTengah(int i, int j);
void tambahBelakang(int i);
void hapusDepan ();
void hapusTengah(int i);
void hapusBelakang(int i);
void tampilData();


int main(){
    int pilihan, i, j;
    do{

	system("cls");
	cout <<"Menu :"<<endl;
    cout << "1. Buat Node awal" <<endl;
    cout << "2. Menambahkan Node" <<endl;
    cout << "3. Menghapus Node" <<endl;
    cout << "4. Menampilkan data" <<endl;
    cout << "5. Keluar"<<endl;
    cout << "Masukkan Pilihan (1..5) : ";
    cin >> pilihan;
    
    system("cls");
	switch (pilihan)	
	{
		case 1: {
			if(isEmpty()){
				cout<<"buat node baru"<<endl;
				cout<<"=============="<<endl;
				cout<<"\nmasukkan nilai :";
				cin>>i;
				cout<<"Nilai "<<i<<" berhasil dimasukkan di node awal"<<endl;
				nodeBaru(i);
			}else{
				cout<<"node awal sudah dibuat"<<endl;
			}
			break;
		}
		case 2: {
			if(isEmpty()){
				cout<<"node awal belum dibuat"<<endl;
			}else{
				system("cls");
				cout<<"1. tambah di depan"<<endl;
				cout<<"2. tambah di belakang"<<endl;
				cout<<"3. tambah di tengah"<<endl;
				cout<<"masukkan pilihan [1....3] : ";cin>>pilihan;
				system("cls");
				if(pilihan == 1){
					cout<<"tambah node didepan"<<endl;
					cout<<"\nmasukkan nilai"; cin>>i;
					tambahDepan(i);
					cout<<"node dengan nilai "<<i<< " berhasil ditambahkan didepan"<<endl;
				} else if(pilihan==2){
					cout<<"tambah node dibelakang"<<endl;
					cout<<"\nMasukkan nilai"; cin>>i;
					tambahBelakang(i);
					cout<<"node dengan nilai "<<i<<" berhasil ditambahkan dibelakang"<<endl;
				} else if(pilihan==3){
					cout<<"tambahkan node ditengah"<<endl;
					cout<<"\nmasukkan nilai"; cin>>i;
					tambahTengah (i,j);
					cout<<"node dengan nilai "<<i<<" berhasil ditambahkan ditengah"<<endl;	
				}else {
					system("cls");
				}
				
			}
			break;
		}
		case 3: {
			if(isEmpty()){
				cout<<"node awal belum dibuat"<<endl;
			}else{
				system("cls");
				cout<<"1. hapus didepan"<<endl;
				cout<<"2. hapus dibelakang"<<endl;
				cout<<"3. hapus ditengah"<<endl;
				cout<<"masukkan pilihan [1...3] : "; cin>>pilihan;
				system ("cls");
				if (pilihan == 1){
					cout<<"node pada posisi depan dengan nilai " <<i<<" berhasil dihapus"<<endl;
					hapusDepan();
				}else if (pilihan == 2){
					cout<<"node  pada posisi belakang dengan nilai "<<i<<" berhasil dihapus"<<endl;
					hapusBelakang(i);
				}else if (pilihan == 3){
					cout<<"node pada posisi tengah dengan nilai "<<i<<" berhasil dihapus"<<endl;
					hapusTengah(i);
				}else{
					system("cls");
				}
			}
			break;
		}
		case 4: {
			if(isEmpty()){
				cout<<"linked list masih kosong"<<endl;
			}else{
				cout<<"isi linked list"<<endl;
				cout<<"==============="<<endl;
				cout<<endl;
				tampilData();
			}
			break;
		}
		case 5: system("cls");{
			return 0;
			break;
		}
		} system("pause");
		}while(pilihan>=1 && pilihan<=5);	
}


void nodeBaru(int i){
    n = new Node;
    n->data = i;
    tail = n;
    head = n;
    tail->next = NULL;
}

void tambahBelakang(int i){
    n = new Node;
    n->data = i;
    tail->next = n;
    tail = n;
    tail->next = NULL;
}

void tambahDepan(int i){
    n = new Node;
    n->data = i;
    n->next = head;
    head = n;
}

void tambahTengah(int i, int j){
    x = head;
    while (x->data !=j) x = x->next;
    n = new Node;
    n->data = i;
    n->next = x->next;
    x->next = n;
}

void hapusDepan (){
    x = head;
    head = head->next;
    delete(x);
    x = NULL;
}

void hapusBelakang(int i){
    x = head;
    while (x->next != tail) x = x->next;
    tail = x;
    delete(x->next);
    tail->next = NULL;
}

void hapusTengah(int i){
    Node *temp = NULL;
    x = head;
    while (x->data != i){
        temp = x;
        x = x->next;
    }
    temp->next = x->next;
    delete(x);
    x = NULL;
}

void tampilData(){
    x = head;
    while (x != NULL){
        cout << x->data << " ";
        x = x->next;
    }
}
bool isEmpty(){
	if ( head==NULL){
		return true;
	}else {
		return false;
	}
}

// linked list adalah elemen yang berurutan yang dihubungkan dengan pointer
