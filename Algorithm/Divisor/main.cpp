#include <iostream>
#include <vector>

using namespace std;

void printDivisors(vector<int> &v) {
    for(const auto &d: v) {
        cout<<d<<" ";
    } cout<<endl;
}

vector<int> getDivisor(int n) {
    vector<int> v;
    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            v.push_back(i);
        }
    }
    return v;
}

vector<int> betterWayToGetDivisor(int n) {
    vector<int> v;
    for(int i=1;i*i<=n;i++) {
        if(i*i==n) {
            v.push_back(i);
        } else if(n%i==0) {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    return v;
}

int main() {
    int n = 15;
    for(int i=1;i<=n;i++) {
        vector<int> v = getDivisor(i);
        cout<<i<<"'s divisors: ";
        printDivisors(v);


        v = betterWayToGetDivisor(i);
        cout<<i<<"'s divisors better way: ";
        printDivisors(v);
        cout<<endl;
    }
    return 0;
}