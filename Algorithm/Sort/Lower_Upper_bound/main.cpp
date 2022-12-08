#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v;
    v = {10,20,30,30,40};

    cout<<"Vector contains: ";
    for(const auto &item: v) {
        cout<<item<<" ";
    } cout<<endl;

    /**
     * vector<int>::iterator lower, upper;
     * lower_bound() returns the index value that is equal or greater than argument.
     * 전달인자 보다 초과하는 값의 인덱스를 리턴.
     */
    auto lower = lower_bound(v.begin(), v.end(), 30);
    cout<<"lower_bound(30) in position at: "<<lower-v.begin()<<endl;

    /**
     * upper_bound() returns the index value that is greater than argument.
     * 전달인자 보다 이상인값의 인덱스를 리턴.
     */
    auto upper = upper_bound(v.begin(), v.end(), 30);
    cout<<"upper_bound(30) in position at: "<<upper-v.begin()<<endl<<endl;
    
    lower = lower_bound(v.begin(), v.end(), 35);
    cout<<"lower_bound(35) in position at: "<<lower-v.begin()<<endl;

    

    return 0;
}