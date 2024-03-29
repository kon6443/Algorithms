#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void removeDuplicates(vector<string> & vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

vector<string> split(string s, char delimiter) {
    vector<string> return_val;
    string temp = "";
    for(const auto &item: s) {
        if(item==delimiter) {
            if(temp=="") continue;
            return_val.push_back(temp);
            temp = "";
        } else {
            temp += item;
        }
    }
    if(temp!="") return_val.push_back(temp);
    return return_val;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<vector<string>> reportList(id_list.size());
    vector<vector<string>> reportVector;
    for(const auto &item: report) {
         reportVector.push_back(split(item, ' '));
    }
    
    // Organize report vector
    for(int i=0;i<reportVector.size();i++) {
        for(int j=0;j<reportList.size();j++) {
            if(id_list[j]==reportVector[i][0]) {
                reportList[j].push_back(reportVector[i][1]);
                break;
            }
        }
    }
    
    // Removing duplicates
    for(auto &ban: reportList) {
        removeDuplicates(ban);
    }
    
    // Counting number of being reported
    map<string, int> warningCount;
    for(const auto &id: id_list) warningCount[id]=0;
    for(int m=0;m<id_list.size();m++) {
        for(int i=0;i<reportList.size();i++) {
            for(int j=0;j<reportList[i].size();j++) {
                if(id_list[m]==reportList[i][j]) {
                    warningCount[id_list[m]]++;
                }
            }
        }
    }
    for(int i=0;i<reportList.size();i++) {
        for(int j=0;j<reportList[i].size();j++) {
            if(warningCount[reportList[i][j]]>=k) answer[i]++;
        }
    }
    return answer;
}