#include <iostream>

using namespace std;

int main{
	int a,b, *c, *d;
	a = 10;
	c = &a;
	d = &b;
	c = d;
	*c = a;
	d = &a;
	*d = a + b;
	
	cout << a << endl << b;
return 0;
}
