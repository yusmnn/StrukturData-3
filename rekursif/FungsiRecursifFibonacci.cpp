#include <iostream>
using namespace std;

int main() {
    int n, f_n, f_n1, f_n2;

    cout << " ===PROGRAM REKURSIF FIBONACCI===\n";
    cout << "Masukkan angka : ";
    cin >> n;

    f_n1 = 1;
    f_n2 = 0;
    f_n = f_n1 + f_n2;
    cout << f_n << " ";
    for( int i = 1; i < n; i++ ) {
        // f_n = f_n1 + f_n2;
        // f_n2 = f_n1;
        // f_n1 = f_n;

        /* agar tidak cout nilai awal */
        f_n2 = f_n1;
        f_n1 = f_n;
        f_n = f_n1 + f_n2;
        cout << f_n << " ";
    }

cin.get();
return 0;
}