#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print2DVector(vector<vector<int>> &v) {
    for(const auto &row: v) {
        for(const auto &r: row) {
            cout<<r<<" ";
        } cout<<endl;
    } cout<<endl;
}

int main() {

    vector<vector<int>> v = {{4,3,5,3}, 
                     {2,6,3,7}, 
                     {6,8,5,1}, 
                     {5,6,1,5}};
    
    cout<<"Before sort by column: "<<endl;
    print2DVector(v);

    sort(v.begin(), v.end(), [](vector<int> &v1, vector<int> &v2) {return v1[3]<v2[3];});
    cout<<"After sort by last column: "<<endl;
    print2DVector(v);

    sort(v.begin(), v.end(), [](vector<int> &v1, vector<int> &v2) {return v1[2]<v2[2];});
    cout<<"After sort by second column from the back: "<<endl;
    print2DVector(v);

    return 0;
}
