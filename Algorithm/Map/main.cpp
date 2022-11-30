#include <iostream>
#include <map>

using namespace std;

// Initializing default value.
struct Node {
    int value = -1;
};

int main() {


    map<int, int> m;
    // m[0]: 0, m[1]: 1, m[2]: 2
    for(int i=0;i<3;i++) {
        m[i] = i;
    }
    // m[3]: 0
    for(int i=0;i<4;i++) {
        cout<<"m["<<i<<"]: "<<m[i]<<endl;
    }
    
    // Initializing default value.
    map<int, Node> d;
    // m[0].value: -1, m[1].value: -1, m[2].value: -1
    for(int i=0;i<3;i++) {
        cout<<"d["<<i<<"].value: "<<d[i].value<<endl;
    }

    return 0;
}

