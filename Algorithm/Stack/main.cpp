#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<int> s;
    
    s.push(1);  // {1}
    s.push(2);  // {1,2}
    s.push(3);  // {1,2,3}
    s.push(4);  // {1,2,3,4}

    s.pop();    // {1,2,3}
    s.pop();    // {1,2}

    int t = s.top();  // t = 2

    // Stack size: 2
    cout<<"Stack size: "<<s.size()<<endl;

    return 0;
}
