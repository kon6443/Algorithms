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
    
    for(const auto &p: v) {
        for(const auto &item: p) {
            cout<<item<<" ";
        } cout<<endl;
    }

    return 0;
}