#include <iostream>
using namespace std;

int fibonacci(int n){
    // cout << "fungsi rekursif " << n << endl;
    if((n == 0) or (n == 1)){
        return n;
    } else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int angka,hasil;
    cout << "Masukkan angka :";
    cin >> angka;
    hasil = fibonacci(angka);

    cout << "hasil : ";
    cout << hasil << endl;
 
    cin.get();
    return 0;
}
