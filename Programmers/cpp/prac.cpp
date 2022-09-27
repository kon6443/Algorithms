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
    
    vector<int> v = {1,2,3};
    do {
        print(v);
    } while (next_permutation(v.begin(), v.end()));
    
    return 0;
}

void print(vector<int> &v) {
    for(int e : v) {
        cout<<" "<<e;
    }
    cout<<endl;
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