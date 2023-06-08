#include <iostream>

using namespace std;

void double_pointer();

int main() {

    double_pointer();

    return 0;
}

void double_pointer() {
    cout<<"----------basic double pointer tutorials.----------"<<endl;
    int number = 10;
    int* ptr = &number;
    int** doublePtr = &ptr;
    cout<<"int number = 10;"<<endl;
    cout<<"int* ptr = &number;"<<endl;
    cout<<"int** doublePtr = &ptr;"<<endl<<endl;

    cout<<"Value of number: "<<number<<endl;
    cout<<"Value of *ptr: "<<*ptr<<endl;
    cout<<"Value of **doublePtr: "<<**doublePtr<<endl<<endl;
    
    cout<<"Value of &number: "<<&number<<endl;
    cout<<"Value of ptr: "<<ptr<<endl;
    cout<<"Value of &ptr: "<<&ptr<<endl;
    cout<<"Value of doublePtr: "<<doublePtr<<endl;
    cout<<"Value of &doublePtr: "<<&doublePtr<<endl<<endl;

    number = 20;
    cout<<"number = 20;"<<endl;
    cout<<"number: "<<number<<", *ptr: "<<*ptr<<", **doublePtr: "<<**doublePtr<<endl<<endl;

    *ptr = 30;
    cout<<"*ptr = 30;"<<endl;
    cout<<"number: "<<number<<", *ptr: "<<*ptr<<", **doublePtr: "<<**doublePtr<<endl<<endl;
    
    **doublePtr = 40;
    cout<<"**doublePtr = 40;"<<endl;
    cout<<"number: "<<number<<", *ptr: "<<*ptr<<", **doublePtr: "<<**doublePtr<<endl<<endl;
}
