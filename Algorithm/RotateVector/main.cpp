#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(string s, vector<int> &v) {
    cout<<s;
    for(const auto &item: v) cout<<item<<" "; cout<<endl;
}

int main() {

    vector<int> v = {1,2,3,4,5};
    print("Before rotating: ", v);

    // Rotating a given vector to the left direction by 1.
    // Require algorithm library. 
    rotate(v.begin(), v.begin()+1, v.end());
    print("After rotating to the left direction: ", v);

    // Rotating a given vector to the right direction by 2. 
    rotate(v.rbegin(), v.rbegin()+2, v.rend());
    print("After rotating to the right direction: ", v);

    return 0;
}

