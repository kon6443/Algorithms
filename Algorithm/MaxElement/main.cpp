#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<int> v = {1,3,5,8,2,6};
    cout<<"v: ";
    for(const auto &item: v) cout<<item<<" "; cout<<endl;

    // max_element()
    // Returning max element's iterator.
    // You have to use pointer to access the object. => *t
    auto t = max_element(v.begin(), v.end());
    cout<<"*t: "<<*t<<endl;

    // To get the index of the value, get the distance from the beginning to itself. 
    int index = distance(v.begin(), t); 
    cout<<"index of the maximum value: "<<index<<endl;


    // min_element()
    // Returning min element's iterator.
    // You have to use pointer to access the object. => *t
    auto c = min_element(v.begin(), v.end());
    cout<<"*c: "<<*c<<endl;

    // To get the index of the value, get the distance from the beginning to itself. 
    int indexC = distance(v.begin(), c);
    cout<<"index of the minimum value: "<<indexC<<endl;

    return 0;
}

