#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void bubbleSort(vector<int> v) {
    for(int i=0;i<v.size();i++) {
        for(int j=i;j<v.size();j++) {
            if(v[i]>v[j]) swap(v[i], v[j]);
        }
    }
    for(const auto &item: v) cout<<item<<" "; cout<<endl;
}

void insertionSort(vector<int> v) {
    for(int i=1;i<v.size();i++) {
        int cursor = v[i];
        int j = i-1;
        while(j>=0 && v[j]>cursor) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = cursor;
    }
    for(const auto &item: v) cout<<item<<" "; cout<<endl;
}

// a b c d
vector<int> mergeSort(vector<int> v) {
    if(v.size()>1) {
        int mid = v.size()/2-1;
        vector<int> left;
        vector<int> right;
        for(int i=0;i<v.size();i++) {
            if(i<=mid) left.push_back(v[i]);
            else right.push_back(v[i]);
        }
        left = mergeSort(left);
        right = mergeSort(right);
        int i = 0;
        int j = 0;

        int k = 0;
        while(i<left.size() && j<right.size()) {
            if(left[i]<=right[j]) {
                v[k] = left[i];
                i++;
            } else {
                v[k] = right[j];
                j++;
            }
            k++;
        }
        while(i<left.size()) {
            v[k] = left[i];
            i++;
            k++;
        }
        while(j<right.size()) {
            v[k] = right[j];
            j++;
            k++;
        }
    }
    return v;
}

int main() {

    vector<int> v = {5, 3, 32, 7, 897, 345, 24, 78, 12, 45};
    cout<<"Original: "<<endl;
    for(const auto &item: v) cout<<item<<" "; cout<<endl;
    cout<<"Bubble: "<<endl;
    bubbleSort(v);
    cout<<"Insertion: "<<endl;
    insertionSort(v);
    cout<<"Merge2: "<<endl;
    vector<int> v2 = mergeSort(v);
    for(const auto &item: v2) cout<<item<<" "; cout<<endl;
    return 0;
}