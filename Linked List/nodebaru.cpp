#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

int isempty(){
    if(head == NULL) return 1;
    else return 0;
}

//prototype
int isempty();
void buatNodeBaru(int i);
void TambahDiDepan(int i);
void tambahDiTengah(int i, int j);
void tambahDiBelakang(int i);

void TampilNilai();


int main() {
    int pil, nilaibaru;
    do {
        start:
        cout << "\nMenu:\n";
        cout << "1. Buat Node Awal\n";
        cout << "2. Tambah Node\n";
        // cout << "3. Hapus Node\n";
        cout << "4. Tampil Data\n";
        // cout << "5. Keluar\n";
        cout << "Masukkan pilihan [1..5] : ";
        cin >> pil;
        system("cls");
            switch (pil){
                case 1: {
                    cout << "Buat Node baru\n";
                    cout << "==============" << endl << endl;
                    cout << "Masukkan nilai : ";
                    
                    if(nilaibaru >= 1) {
                      
                        cout << "Node awal/baru sudah dibuat..." << endl;
                        break;
                    }

                    cin>> nilaibaru;

                    if(nilaibaru >= 1) {
                        cout << " Nilai " << nilaibaru <<" berhasil dimasukkan di node awal." << endl;
                        break; 
                    }
                        
                }
                case 2: {
                    do  {
                        cout << "1.Tambah Node di Depan" << endl;
                        cout << "2.Tambah Node di Belakang" << endl;
                        cout << "3.Tambah Node di tengah" << endl;
                        cout << "4.Batal" << endl;
                        cout << "\nMasukkan pilihan (1..4) : ";
                        cin >> pil;
                        switch (pil) {
                            case 1: {
                                cout << "Tambah Node di Depan" << endl;
                                cout << "====================\n" << endl;
                                cout << "Masukkan Nilai = ";
                                cin >> nilaibaru;
                                TambahDiDepan(nilaibaru);
                                cout << " Node dengan nilai " << nilaibaru << " berhasil ditambahkan pada posisi depan." << endl;
                                break;
                            }
                            case 2: {
                                cout << "Tambah Node di belakang" << endl;
                                cout << "====================\n" << endl;
                                cout << "Masukkan Nilai = ";
                                cin >> nilaibaru;
                                tambahDiBelakang(nilaibaru);
                                cout << " Node dengan nilai " << nilaibaru << " berhasil dimasukkan pada posisi belakang." << endl;
                                break;
                            }
                            case 3: {
                                int nilaiinput;
                                cout << "Tambah Node di tengah" << endl;
                                cout << "====================\n" << endl;
                                cout << "Masukkan Nilai = ";
                                cin >> nilaiinput;
                                tambahDiTengah(nilaibaru, nilaiinput);
                                cout << " Nilai " << nilaiinput << " telah masuk" << endl;
                                break;
                            }
                            case 4: {
                                goto start;
                                system("cls");
                                break;
                            }
                       }
                    }
                    while (pil>=1 && pil <= 4);
                } 
                case 3: {

                }   
                case 4: {
                    cout << "\n Isi dari Linked list" << endl;
                    cout << "======================\n" << endl;
                    TampilNilai();
                    cout << endl << endl;
                    break;
                }                                                                          
            default : {
                goto start;
            }           
        } 
    }
    while (pil>=1 && pil <= 5);


    return 0;
}


void buatNodeBaru(int i){
	n = new Node;
	n->data = i;
	tail = n;
	head = n;
	tail->next = NULL;
}

void TambahDiDepan(int i){
    n = new Node;
    n->data = i;
    n->next = head;
    head = n;
}

void tambahDiBelakang(int i){
	n = new Node;
	n->data = i;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiTengah(int i, int j){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = i;
	n->next = x->next;
	x->next = n;
}

void TampilNilai(){
    x = head;
    while(x !=NULL){
    cout << x->data << " ";
    x = x->next;
    }
}