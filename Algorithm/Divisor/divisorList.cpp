#include <iostream>
#include <vector>

using namespace std;

int main() {

    /**
     * Program that making a list that contains numbers of divisors.
     */

    int limit = 10;
    vector<int> dp(limit+1);
    for(int i=1;i<=limit;i++) {
        for(int j=i;j<=limit;j+=i) {
            cout<<j<<" ";
            dp[j]++;
        } cout<<endl;
    }cout<<endl<<endl;

    for(int i=1;i<dp.size();i++) {
        cout<<i<<": "<<dp[i]<<endl;
    }

    return 0;
}