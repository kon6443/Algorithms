#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getNumOfRest(vector<int> lottos, vector<int> win_nums) {
    vector<int> difference;
    set_difference(
        win_nums.begin(), win_nums.end(),
        lottos.begin(), lottos.end(),
        back_inserter( difference )
    );
    return difference.size();
}

int getBestCase(vector<int> lottos, vector<int> win_nums) {
    int answer = 6;
    int numOfRest = getNumOfRest(lottos, win_nums);
    if(numOfRest==0) return 1;
    int NumOfZeros = count(lottos.begin(), lottos.end(), 0);
    int correct_num = 6-numOfRest+NumOfZeros;
    if(correct_num>1) answer = 7-correct_num;
    return answer;
}

int getWorstCase(vector<int> lottos, vector<int> win_nums) {
    int correct_num = 6-getNumOfRest(lottos, win_nums);
    int answer = 6;
    if(correct_num>1) answer = 7-correct_num;
    return answer;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    answer.push_back(getBestCase(lottos, win_nums));
    answer.push_back(getWorstCase(lottos, win_nums));
    return answer;
}

