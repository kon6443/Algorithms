#include <string>
#include <vector>
#include <iostream>

using namespace std;

int checkDamage(vector<vector<int>> &board) {
    int goodConditionBuilding = 0;
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            if(board[i][j]>0) goodConditionBuilding++;
        }
    }
    return goodConditionBuilding;
}

void printVector(vector<int> &v) {
    for(const auto &item: v) cout<<item<<" ";
    cout<<endl;
}

void print2DVector(vector<vector<int>> &v) {
    for(int i=0;i<v.size();i++) printVector(v[i]);
    cout<<endl;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<int> v(board[0].size()+1, 0);
    vector<vector<int>> prefixSum(board.size()+1, v);
    for(int i=0;i<skill.size();i++) {
        if(skill[i][0]==1) {
            // top left
            prefixSum[skill[i][1]][skill[i][2]] -= skill[i][5];
            // top right
            prefixSum[skill[i][1]][skill[i][4]+1] += skill[i][5];
            // bottom left
            prefixSum[skill[i][3]+1][skill[i][2]] += skill[i][5];
            // bottom right
            prefixSum[skill[i][3]+1][skill[i][4]+1] -= skill[i][5];
        } else if(skill[i][0]==2) {
            // top left
            prefixSum[skill[i][1]][skill[i][2]] += skill[i][5];
            // top right
            prefixSum[skill[i][1]][skill[i][4]+1] -= skill[i][5];
            // bottom left
            prefixSum[skill[i][3]+1][skill[i][2]] -= skill[i][5];
            // bottom right
            prefixSum[skill[i][3]+1][skill[i][4]+1] += skill[i][5];
        }
    }
    for(int i=0;i<prefixSum.size();i++) {
        for(int j=0;j<prefixSum[i].size();j++) {
            prefixSum[i][j+1] += prefixSum[i][j];
        }
    }
    for(int i=0;i<prefixSum[0].size()-1;i++) {
        for(int j=0;j<prefixSum.size()-1;j++) {
            prefixSum[j+1][i] += prefixSum[j][i];
        }
    }
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            board[i][j] += prefixSum[i][j];
        }
    }
    answer = checkDamage(board);
    return answer;
}

