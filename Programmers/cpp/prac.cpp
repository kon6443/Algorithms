#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void foo(int &a);
void foo2(int a);

int main() {
    
    map<char, char> m;
    m['A'] = '1';
    m['B'] = '2';
    m['C'] = '3';
    cout<<m['A']<<endl;
    cout<<m['B']<<endl;
    cout<<m['C']<<endl;
    
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