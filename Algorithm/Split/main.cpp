#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string s = "abc def gh ij klm no";
    vector<string> v;
 
    string delimiter = " ";
    auto start = 0U;
    auto end = s.find(delimiter);
    string token = "";
    while (end != string::npos) {
        token = s.substr(start, end-start);
        v.push_back(token);
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    v.push_back(s.substr(start));

    for(const auto &item: v) cout<<item<<endl;

    return 0;
}
