#include <iostream>
using namespace std;

struct tnode {
    int data;
    tnode *next;
};

tnode *head;
void init(){
    head = NULL;
}

int isempty(){
    if(head == NULL) return 1;
    else return 0;
}

void insertdepan(int nilaibaru) {
    tnode *baru;
    baru = new tnode;
    baru -> data = nilaibaru;
    baru -> next = NULL;
    if(isempty()==1){
        head = baru;
        head -> next = NULL;
    } else {
        baru -> next = head;
        head = baru;
    }
    cout << "data masuk";
}

void insertbelakang(int nilaibaru) {
    tnode *baru, *bantu;
    baru = new tnode;
    baru -> data = nilaibaru;
    baru -> next = NULL;
    if(isempty()==1) {
        head = baru;
        head -> next = NULL;
    }
    else {
        bantu = head;
        while (bantu -> next != NULL) {bantu = bantu -> next;}
        bantu -> next = baru;
    }
    cout << "Data masuk";
}

void tampil() {
    tnode *bantu;
    bantu = head;
    if(isempty()==0) {
        while(bantu != NULL){
            cout << bantu -> data << " ";
            bantu = bantu -> next;
        }
        cout << " ";
    } 
    else cout << "Masih kosong\n";
}

void hapusdepan() {
    tnode *hapus;
    int d;
    if(isempty()==0){
        if(head -> next != NULL){
            hapus = head;
            d = hapus -> data;
            head = head -> next;
            delete hapus;
        }
        else {
            d = head -> data;
            head = NULL;
        }
        cout << d << "Terhapus";
    }
    else cout << "Masih kosong\n";
}

void hapusbelakang(){
    tnode *hapus, *bantu;
    int d;
    if (isempty()==0){
        if(head -> next != NULL){
            bantu = head;
            while(bantu -> next -> next = NULL){
                bantu = bantu -> next;
            }
            hapus = bantu -> next;
            d = hapus -> data;
            bantu -> next = NULL;
            delete hapus;
        }
        else {
            d = head -> data;
            head = NULL;
        }
        cout << d << "terhapus";
    }
    else cout << "Masih kosong\n";
}

int main() {
    int pil, nilaibaru;
    cout << "Menu : ";

    do {
        cout << "\n";
        cout << "\n1. Buat Node Awal";
        cout << "\n2. Insert belakang";
        cout << "\n3. Delete depan";
        cout << "\n4. Delete belakang";
        cout << "\n5. Tampil data";
        cout << "\n Silahkan masukkan pilihan anda : ";
        cin >> pil;
        switch (pil){
            case 1 : {
                cout << "Masukkan nilai : ";
                cin>> nilaibaru;
                insertdepan(nilaibaru);
                break;
            }
            case 2 : {
                cout << "Masukkan data : ";
                cin>> nilaibaru;
                insertbelakang(nilaibaru);
                break;
            }
            case 3 : {
                hapusdepan();
                break;
            }
            case 4 : {
                hapusbelakang();
                break;
            }
            case 5 : {
                tampil();
                break;
            }
            default : {
                cout << "\n Maaf, tidak ada dalam pilihan";
            }  
        } 
    }
    while (pil>=1 && pil <= 5);


    return 0;
}