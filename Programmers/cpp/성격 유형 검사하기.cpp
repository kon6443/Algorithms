#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n = survey.size();
    map <char, int> mbti;
    string variations = "RTCFJMAN";
    for(int i=0;i<variations.size();i++) mbti[variations[i]] = 0;
    for(int i=0;i<n;i++) {
        if(choices[i]<4) {
            mbti[survey[i][0]] += 4-choices[i];
        } else if(choices[i]>4) {
            mbti[survey[i][1]] += choices[i]-4;
        }
    }
    for(int i=0;i<variations.size();i+=2) {
        if(mbti[variations[i]]>=mbti[variations[i+1]]) answer += variations[i];
        else answer += variations[i+1];
    }
    return answer;
}

