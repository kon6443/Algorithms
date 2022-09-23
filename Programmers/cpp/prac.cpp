#include <iostream>

using namespace std;

void foo(int &a);
void foo2(int a);

int main() {

    int a = 0;
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;

    foo(a);
    foo2(a);

    return 0;
}

void foo(int &a) {
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
}

void foo2(int a) {
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
}