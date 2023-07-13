#include <string>
#include <vector>
#include <map>

using namespace std;

int getOvertakingCount(vector<string> &callings, int index) {
    int count = 1;
    int overtakingSize = callings.size();
    while(index+1!=overtakingSize && callings[index]==callings[index+1]) {
        count++;
        index++;
    }
    return count;
}

void updateRank(map<string, int> &nameToRank, map<int, string> &rankToName, string name, int overtakingCount) {
    string currentName = "";
    for(int i=0;i<overtakingCount;i++) {
        rankToName[nameToRank[name]-i] = rankToName[nameToRank[name]-(i+1)];
        nameToRank[rankToName[nameToRank[name]-i]] += 1;
    }
    nameToRank[name] -= overtakingCount;
    rankToName[nameToRank[name]] = name;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> nameToRank;
    map<int, string> rankToName;
    for(int i=0;i<players.size();i++) {
        nameToRank[players[i]] = i+1;
        rankToName[i+1] = players[i];
    }
    for(int i=0;i<callings.size();) {
        int overtakingCount = getOvertakingCount(callings, i);
        updateRank(nameToRank, rankToName, callings[i], overtakingCount);
        i += overtakingCount;
    }
    vector<string> answer;
    for(int i=1;i<=players.size();i++) {
        answer.push_back(rankToName[i]);
    }
    return answer;
}
