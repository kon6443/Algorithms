#include <string>
#include <vector>
#include <iostream>

using namespace std;

auto getScore(vector<int> &apeach, vector<int> &lion) {
    int apeach_score, lion_score = 0;
    for(int i=0;i<apeach.size();i++) {
        if(apeach[i]>=lion[i]) apeach_score += 10-i;
        else lion_score += 10-i;
    }
}

vector<vector<int>> getLargestGaps() {
    
}

003
012
vector<int> getPossibility(int &n, vector<int> &previous) {
    vector<int> v;
    while(v[0]==n) {
        for(int i=1;i<11;i++) {
            if(previous[i]==n) {
                v = previous;
                v[i-1]++;
                
            } else if(previous[i]>0) {
                v = previous;
                v[i]++;
                v[i+1]--;
            }
        }
    }
    return v;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int apeach_score, lion_score = 0;
    vector<int> v(11);
    vector<vector<int>> possibilities(v.size());
    
    // get all possibillities
    
    // get vectors that has the largest gap
    
    // get a vector that consists of the lowest values
    auto [apeach_score, lion_score] = getScore(info, );
    return answer;
}