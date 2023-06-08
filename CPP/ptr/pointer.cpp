#include <iostream>

using namespace std;

void basic_pointer();

int main() {

    basic_pointer();

    return 0;
}

void basic_pointer() {
    cout<<"----------basic pointer tutorials.----------"<<endl;
    int number = 10;

    // Declare a pointer variable with type of int.
    int* ptr;

    // Assign the address of 'number' variable to the pointer variable.
    ptr = &number;
    cout<<"int number = 10;"<<endl;
    cout<<"int* ptr;"<<endl;
    cout<<"ptr = &number;"<<endl;
    cout<<"number:"<<number<<", *ptr: "<<*ptr<<endl<<endl;

    *ptr = 20;
    cout<<"*ptr = 20;"<<endl;
    cout<<"number:"<<number<<", *ptr: "<<*ptr<<endl<<endl;

    number = 30;
    cout<<"number = 30;"<<endl;
    cout<<"number:"<<number<<", *ptr: "<<*ptr<<endl<<endl;

    cout<<"&number: "<<&number<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"They holds the same address. Thus, if you change either of them, they both will be changed."<<endl<<endl;
}
