#include <iostream>
#include <map>

using namespace std;

int recursiveFactorialOf(int x) {
    if(x==1) return 1;
    return x*recursiveFactorialOf(x-1);
}

map<int, int> m;

int dpFactorialOf(int x) {
    if(x==1) return 1;
    if(m[x]==0) m[x] = x*dpFactorialOf(x-1);
    return m[x];
}

int main() {
    cout<<"recursiveFactorialOf: "<<recursiveFactorialOf(4)<<endl;
    cout<<"dpFactorialOf: "<<dpFactorialOf(4)<<endl;
    return 0;
}