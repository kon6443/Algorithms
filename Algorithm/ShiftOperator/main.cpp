#include <iostream>

using namespace std;

int main() {

    // Decimal number 3 is 0011 in binary.
    int a = 3;
    cout<<"a is: "<<a<<endl;

    // a is left shifted by 1 so it is 0110 in binary.
    int temp = a << 1;
    cout<<"a << 1 is: "<<temp<<endl;
    
    return 0;
}
