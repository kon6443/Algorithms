#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> n = {1,2,3,4};
    vector<vector<int>> v;
    do {
        vector<int> cursor;
        for(const auto &item: n) {
            cursor.push_back(item);
        } 
        v.push_back(cursor);
    } while(next_permutation(n.begin(),n.end()));
    
    for(int i=0;i<v.size();i++) {
        cout<<i<<": ";
        for(const auto &item: v[i]) {
            cout<<item<<" ";
        } cout<<endl;
    }

    return 0;
}