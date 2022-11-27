#include <iostream>
#include <string>

using namespace std;


void charToInt(char);

int main() {
    
    // Convert int to string.
    int n = 10;
    string nAsString = to_string(n);
    

    // Convert string to char.
    for(const auto &item: nAsString) {
        cout<<item<<": "<<typeid(item).name()<<endl;
    }

    // Convert char to int.
    // In ASCII code, the numbers(digits) start from 48.
    for(const auto &item: nAsString) {
        int temp = (int)item-48;
        cout<<temp<<endl;
    }
    
    return 0;
}

