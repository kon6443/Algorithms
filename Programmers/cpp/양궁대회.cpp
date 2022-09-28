#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int max_gap = 0;
vector<vector<int>> possibilities;

vector<int> getAnswer(vector<vector<int>> &possibilities) {
    int length = possibilities.size();
    if(length==1) return possibilities[0];    
    int max, cursor = 0;
    for(int i=10;i>=0;i--) {
        max, cursor = 0;
        for(int j=0;j<length;j++) {
            if(possibilities[j][i]>max) {
                max = possibilities[j][i];
                cursor = j;
            }
        }
        if(max!=0) break;
    }
    return possibilities[cursor];
}

int getGap(vector<int> &apeach, vector<int> &lion) {
    int apeach_score, lion_score = 0;
    for(int i=0;i<apeach.size();i++) {
        if(apeach[i]>=lion[i]) {
            if(apeach[i]==0&&lion[i]==0) continue;
            apeach_score += 10-i;
        }
        else lion_score += 10-i;
    }
    if(lion_score - apeach_score==0) return -1;
    return lion_score - apeach_score;
}

void getPossibilities(int n, vector<int> &apeach, int index, vector<int> lion) {
    if(n==0 || index==11) {
        lion[10] += n;
        int gap = getGap(apeach, lion);
        if(gap < 0) return;
        if(max_gap == gap) {
            possibilities.push_back(lion);
        } else if(max_gap < gap) {
            max_gap = gap;
            possibilities.clear();
            possibilities.push_back(lion);
        }
        return;
    }
    
    // In case that lion is shooting arrows.
    if(apeach[index]<n) {
        lion[index] += apeach[index]+1;
        getPossibilities(n-apeach[index]-1, apeach, index+1, lion);
        lion[index] -= apeach[index]+1;
    }
    
    // In case that lion is not shooting arrows.
    getPossibilities(n, apeach, index+1, lion);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion(11);
    
    // get all possibilities efficiently.
    getPossibilities(n, info, 0, lion);
    
    // get a vector that consists of the lowest values
    if(possibilities.size()==0) {
        answer = {-1};
    } else {
        answer = getAnswer(possibilities);
    }
    return answer;
}