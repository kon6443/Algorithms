#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<int> v = {1,3,5,8,2,6};
    cout<<"v: ";
    for(const auto &item: v) cout<<item<<" "; cout<<endl;

    // Returning max element's iterator.
    // You have to use pointer to access the object. => *t
    auto t = max_element(v.begin(), v.end());
    cout<<"*t: "<<*t<<endl;

    // To get the index of the value, get the distance from the beginning to itself. 
    int index = distance(v.begin(), t); 
    cout<<"index of the maximum value: "<<index<<endl;

    return 0;
}

