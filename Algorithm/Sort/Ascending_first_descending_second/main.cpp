#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printPairVector(vector<pair<int, int>> &v) {
    for(const auto &item: v) {
        cout<<item.first<<","<<item.second<<endl;
    }
}

int comparison(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main() {
    vector<int> first = {1,3,3,2,5};
    vector<pair<int, int>> v;
    for(int i=0;i<first.size();i++) {
        v.push_back(make_pair(first[i], i+1));
    }
    cout<<"Before sorting a vector of pairs: "<<endl;
    printPairVector(v); cout<<endl;
    
    sort(v.begin(), v.end(), comparison);
    cout<<"After sorting a vector of pairs by ascending first element, descending second element: "<<endl;
    printPairVector(v);
    
    return 0;
}