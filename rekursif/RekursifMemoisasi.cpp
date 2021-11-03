#include <iostream>
using namespace std;

int f[50];

int fibonacci(int n);

int main (){

    for(int i = 1; i <= 50; i++){
        f[i] = -1;
    }
    
    int n;
    cout << "Masukkan angka : ";
    cin >> n;
    int hasil = fibonacci(n);
    cout << "Hasil : " << hasil;

    cin.get();
    return 0;
}

int fibonacci(int n){
    cout << "Fungsi Rekursif " << n << endl;
    if(n <= 1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n] = fibonacci(n - 1) + fibonacci(n -2);
    return f[n];
}


