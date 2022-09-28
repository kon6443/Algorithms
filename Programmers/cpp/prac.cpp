#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void foo(int &a);
void foo2(int a);
void pracMap();

int main() {
    
    int a = 20;
    string s = to_string(a);
    cout<<s<<endl;
    
    return 0;
}

void pracMap() {
    map<char, char> m;
    m['A'] = '1';
    m['B'] = '2';
    m['C'] = '3';
    cout<<m['A']<<endl;
    cout<<m['B']<<endl;
    cout<<m['C']<<endl;
}

void foo2(int a) {
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
}

void foo(int &a) {
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
}