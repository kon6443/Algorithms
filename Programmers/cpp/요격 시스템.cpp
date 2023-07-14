#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareSecond(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), compareSecond);
    int end = 0;
    for(int i=0;i<targets.size();i++) {
        int s = targets[i][0];
        int e = targets[i][1];
        if(s<end) {
            continue;
        } else {
            end = e;
            answer++;
        }
    }
    return answer;
}

