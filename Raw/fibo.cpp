#include <iostream>
#include <map>

using namespace std;

int recursiveFibo(int x) {
    if(x<=1) return 1;
    return recursiveFibo(x-1)+recursiveFibo(x-2);
}

map<int, int> m;
// 1 2 3 5 8
int dpFibo(int x) {
    if(x<=1) return 1;
    if(m[x]==0) m[x] = dpFibo(x-1) + dpFibo(x-2);
    return m[x];
}

int main() {
    cout<<"1: "<<recursiveFibo(7)<<endl;
    cout<<"2: "<<dpFibo(7)<<endl;
    return 0;
}