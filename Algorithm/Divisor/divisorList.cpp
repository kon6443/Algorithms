#include <iostream>
#include <map>

using namespace std;

int main() {

    /**
     * Program that making a list that contains numbers of divisors.
     */

    map<int,int> dp;
    int limit = 20;
    for(int i=1;i<=limit;i++) {
        for(int j=i;j<=limit;j+=i) {
            dp[j]++;
        }
    }

    for(const auto &i: dp) {
        cout<<i.first<<": "<<i.second<<endl;
    }

    return 0;
}