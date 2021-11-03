#include <iostream>
using namespace std;

int F[51];

int Fib(int n){
    if(n <= 1){
        return n;
   }
   if(F[n] != -1){
        return F[n];
   }
   F[n] = Fib(n-1) +Fib(n-2);
    return F[n];
}
int main() {
    for( int i = 0; i < 51; i++){
        F[i] = -1;
    }

    F[0] = 0; F[1] = 1;

    int n;
    cout << " Keluarkan Nilai : " ;
    cin >> n;
    int result = Fib(n);
    cout << result;

return 0;
}