#include <iostream>
using namespace std;

struct Node{
int data;
Node *next;
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void createNode(int i){
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
    x =head;
    head = head->next;
    delete(x);
}

void hapusDiBelakang(){
    x =head;
    while(x->next != tail) x=x->next;
    tail = x;
    delete(x->next);
    tail->next = NULL;
}

void tampilData(){
    x=head;
    while(x!=NULL){
    cout << x->data << " ";
    x= x->next;
    }
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
}


int main (){
    int pil,databaru;
    do{
    start:
    cout << "menu :\n";
    cout << "1.Buat Node Awal\n";
    cout << "2.Tambah Node\n";
    cout << "3.Hapus Node\n";
    cout << "4.Tampil Data\n";
    cout << "5.keluar\n";
    cout << "Silahkan Masukan Pilihan (1...5) :"; cin >> pil;
    system("cls");
    switch (pil){
    case 1:{
    cout << "Buat Node Baru" << endl;
    cout << "==============\n" << endl;
    cout << "Masukkan Data = ";
    cin >> databaru;
    createNode(databaru);
    system("cls");
    break;
    }
        case 2:{
        cout << "1.Tambah Node di Depan" << endl;
        cout << "2.Tambah Node di Belakang" << endl;
        cout << "3.Keluar" << endl;
        cout << "\nMasukkan pilihan (1...3) : "; cin >> pil;
        system ("cls");
        switch (pil){
            case 1:{
                cout << "Tambah Node di Depan" << endl;
                cout << "====================\n" << endl;
                cout << "Masukkan Data = ";
                cin >> databaru;
                tambahDiDepan(databaru);
                system("cls");
            break;
            }
            case 2:{
                cout << "Tambah Node di Belakang" << endl;
                cout << "=======================\n" << endl;
                cout << "Masukkan Data = ";
                cin >> databaru;
                tambahDiBelakang(databaru);
                system("cls");
            break;
            }
            case 3:{
                goto start;
                system("cls");
                break;
                }
            }
        system("cls");
        break;
        }
        case 3:{
            cout << "1.Hapus Node di Depan" << endl;
            cout << "2.Hapus Node di Belakang" << endl;
            cout << "3.Keluar" << endl;
            cout << "\nMasukkan pilihan (1...3) : "; cin >> pil;
            system("cls");
            switch (pil){
                case 1:{
                    hapusDiDepan();
                    system("cls");
                    break;
                }
                case 2:{
                    hapusDiBelakang();
                    system("cls");
                    break;
                }
                case 3:{
                    goto start;
                    system("cls");
                    break;
                    }
                }
            system("cls");
            break;
            }
        case 4:{
            cout << "\nisi dari Linked List" << endl;
            cout << "====================\n" << endl;
            tampilData();
            cout << endl << endl;
            break;
        }
        case 5:{
            return 0;
            break;
        }
            default :{
            goto start;
            }
        }
    }while(pil>=1 && pil<= 5);
}