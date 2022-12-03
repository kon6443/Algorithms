#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A = "hello";
string B = "ohell";

/**
 * Problem: Rotating string to the right side means shift every elements of the string to the right side. 
 * The right most element goes to the left most element.
 * Find the rotated number that A to be B.
 * 
 * Function foo1 and function foo2 are doing the same thing.
 */

int foo1(string A, string B) {
    int answer = 0;
    for(int i=0;i<A.size();i++) {
        if(A==B) return answer;
        rotate(A.rbegin(), A.rbegin()+1, A.rend());
        answer++;
    }
    return -1;
}

int foo2(string A, string B) {
    B += B;
    return B.find(A);
}

int main() {

    cout<<"foo1: "<<foo1(A, B)<<endl;
    cout<<"foo2: "<<foo2(A, B)<<endl;

    return 0;
}

