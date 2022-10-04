#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getAnswer(vector<int> &q1, vector<int> &q2) {
    int answer = 0;
    unsigned long long s1 = 0;
    unsigned long long s2 = 0;
    for(const auto &item: q1) s1 += item;
    for(const auto &item: q2) s2 += item;
    if((s1+s2)%2) return -1;
    unsigned long long target = (s1+s2)/2;
    int i = 0; int j = q1.size();
    vector<int> v;
    v = q1;
    for(const auto &item: q2) v.push_back(item);
    unsigned long long cur = s1;
    while(j<v.size() && i<=j) {
        if(cur==target) {
            return answer;
        } else if(cur<target) {
            cur += v[j];
            j++;
        } else {
            cur -= v[i];
            i++;
        }
        answer++;
    }
    return -1;
}

int solution(vector<int> queue1, vector<int> queue2) {
    return getAnswer(queue1, queue2);
}

