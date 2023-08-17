#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Assignment {
    string name;
    int start_time;
    int remaining_time;
};

bool compareByTime(const Assignment& a, const Assignment& b) {
    return a.start_time < b.start_time; // Compare by the second element (time)
}

int convertTimeFormatToI(string &time) {
    int colonPos = time.find(':');
    int totalMin = stoi(time.substr(0,colonPos))*60; // Adding hours.
    totalMin += stoi(time.substr(colonPos+1)); // Adding minutes.
    return totalMin;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Assignment> v;
    for(int i=0;i<plans.size();i++) {
        int start_time = convertTimeFormatToI(plans[i][1]);
        Assignment assignment({plans[i][0], start_time, stoi(plans[i][2])});
        v.push_back(assignment);
    }
    sort(v.begin(), v.end(), compareByTime);    
    int current_time = 0;
    stack<Assignment> s;
    while(v.size()) {
        Assignment assignment;
        if(s.size()) {
            if(current_time<v[0].start_time) {
                // When it is not time to do the new assignment yet.
                assignment = s.top();
                s.pop();
            } else {
                // When it is time to do the new assignment.
                assignment = v[0];
                current_time = assignment.start_time;
                v.erase(v.begin());
                if(v.size()==0) {
                    answer.push_back(assignment.name);
                    continue;
                }
            }
        } else {
            // There exists only v and no s.
            assignment = v[0];
            current_time = assignment.start_time;
            v.erase(v.begin());
        }
        
        if(v.size()) {
            if(current_time+assignment.remaining_time <= v[0].start_time) {
                answer.push_back(assignment.name);
                current_time = current_time+assignment.remaining_time;
            } else {
                assignment.remaining_time = current_time+assignment.remaining_time - v[0].start_time;
                s.push(assignment);
                current_time = v[0].start_time;
            }
            continue;
        }
        answer.push_back(assignment.name);
    }
    
    while(s.size()) {
        Assignment assignment = s.top();
        s.pop();
        answer.push_back(assignment.name);
    }
    return answer;
}