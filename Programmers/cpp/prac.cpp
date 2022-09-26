#include <iostream>
#include <vector>
#include <string>

using namespace std;

void foo(int &a);
void foo2(int a);

int main() {
    
    vector<int> v(5, 0);
    for(auto &item: v) cout<<&item<<endl;
    cout<<endl;
    cout<<&v[0]<<endl;
    &v[1] = &v[0];
    // cout<<&v[0]<<&v[1]<<endl;
    cout<<endl;
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