#include <iostream>

using namespace std;

struct node{
    int data;
    node *link;
};
node *top= NULL, *n, *x;
int jml = 0;

void push(int i){
n -> data;
n.data = i;
n->link = top;
top = n;
jml = jml+1;

}

int main(){
    push(12);


    return 0;
}