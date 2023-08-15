#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int s = 0, e = 0, sum = 0;
    int minLength = sequence.size() + 1; // Initialize with a larger value

    while(e<=sequence.size()) {
        if(sum<k) {
            sum += sequence[e];
            e++;
        } else if(sum>=k) {
            if(sum==k && e-s<minLength) {
                minLength = e-s;
                answer = {s, e-1};
            }
            sum -= sequence[s];
            s++;
        }
    }
    return answer;
}

