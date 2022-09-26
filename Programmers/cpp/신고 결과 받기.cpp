#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
    
    for(int i=0;i<reportList.size();i++) {
        cout<<id_list[i]<<": ";
        for(int j=0;j<reportList[i].size();j++) {
            cout<<reportList[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
    
    // Counting number of being reported
    vector<int> count(id_list.size(), 0);
    for(int m=0;m<id_list.size();m++) {
        for(int i=0;i<reportList.size();i++) {
            for(int j=0;j<reportList[i].size();j++) {
                if(id_list[m]==reportList[i][j]) {
                    count[m]++;
                }
            }
        }
    }
    for(const auto &item: count) cout<<item<<" ";
    cout<<endl;
    for(int i=0;i<id_list.size();i++) {
        for(int j=0;j<reportList.size();j++) {
            for(int m=0;m<reportList[j].size();m++) {
                if(reportList[j][m]==id_list[i]) answer[i]++;
            }
        }
    }
    return answer;
}