#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void foo(int &a);
void foo2(int a);
void pracMap();
void pracConvert();
void printVector(vector<T> &v);

int main() {
    int money = 12;
    int tax = money/10;
    cout<<tax<<endl;
    cout<<money-tax<<endl;

    return 0;
}

template<typename T>
void printVector(vector<T> &v) {
    for(const auto &item: v) cout<<item<<" ";
    cout<<endl;
}

void pracConvert() {
    int a = 20;
    string s = to_string(a);
    cout<<s<<endl;
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