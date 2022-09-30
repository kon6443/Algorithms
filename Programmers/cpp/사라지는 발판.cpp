#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ret_obj {
    bool winFlag;
    int score;
};

vector<int> dxs = {1, 0, -1, 0};
vector<int> dys = {0, 1, 0, -1};
ret_obj moveA(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy);
ret_obj moveB(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy);

bool isCursorOutside(vector<vector<int>> &board, int nx, int ny) {
    if(0>=nx || nx>=board.size()) return true;
    if(0>=ny || ny>=board[0].size()) return true;
    return false;
}

bool checkSinkhole(vector<vector<int>> &board, vector<int> &cursor) {
    if(board[cursor[0]][cursor[1]]==0) return true;
    return false;
}

bool isStuck(vector<vector<int>> &board, vector<int> &cursor) {
    for(int i=0;i<4;i++) {
        if(0>=cursor[0]+dxs[i] || cursor[0]+dxs[i]>=board.size()) continue;
        if(0>=cursor[1]+dys[i] || cursor[1]+dys[i]>=board[0].size()) continue;
        if(board[cursor[0]+dxs[i]][cursor[1]+dys[i]]==1) return false;
    }
    return true;
}

ret_obj moveB(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy) {
    ret_obj ret_obj;
    ret_obj.winFlag = false;
    ret_obj.score = 0;
    if(isStuck(board, bloc)) return ret_obj;
    if(isCursorOutside(board, bloc[0]+dx, bloc[1]+dy)) return ret_obj;
    if(board[bloc[0]+dx][bloc[1]+dy]==0) return ret_obj;
    
    board[bloc[0]][bloc[1]] = 0;
    bloc[0] += dx;
    bloc[1] += dy;
    
    if(checkSinkhole(board, aloc)) {
        ret_obj.winFlag = true;
        ret_obj.score = 1;
        return ret_obj;
    }
    
    vector<ret_obj> res_win;
    vector<ret_obj> res_lose;
    ret_obj temp;
    for(int i=0;i<4;i++) {
        temp = moveA(board, aloc, bloc, dxs[i], dys[i]);
        if(temp.winFlag == true) res_win.push_back(temp);
        else res_lose.push_back(temp);
    }
    if(res_win.size()==0) {
        // When there is no win scenario
        int max_val = res_lose[i].score;
        for(int i=1;i<res_lose.size();i++) {
            max_val = max(max_val, res_lose[i].score);
        }
        ret_obj.score = max_val;
        return ret_obj;
    }
    int betterValue = res[0].score;
    for(int i=0;i<res_win.size();i++) {
        betterValue = min(betterValue, res[i].score);
    }
    ret_obj.score = betterValue;
    return ret_obj;
}

ret_obj moveA(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy) {
    ret_obj ret_obj;
    ret_obj.winFlag = false;
    ret_obj.score = 0;
    
    if(isStuck(board, aloc)) return ret_obj;
    if(isCursorOutside(board, aloc[0]+dx, aloc[1]+dy)) return ret_obj;
    if(board[aloc[0]+dx][aloc[1]+dy]==0) return ret_obj;
    
    board[aloc[0]][aloc[1]] = 0;
    aloc[0] += dx;
    aloc[1] += dy;
    
    if(checkSinkhole(board, bloc)) {
        ret_obj.winFlag = true;
        ret_obj.score = 1;
        return ret_obj;
    }
    
    vector<ret_obj> res_win;
    vector<ret_obj> res_lose;
    ret_obj temp;
    for(int i=0;i<4;i++) {
        temp = moveB(board, aloc, bloc, dxs[i], dys[i]);
        if(temp.winFlag == true) res_win.push_back(temp);
        else res_lose.push_back(temp);
    }
    if(res_win.size()==0) {
        // When there is no win scenario
        int max_val = res_lose[i].score;
        for(int i=1;i<res_lose.size();i++) {
            max_val = max(max_val, res_lose[i].score);
        }
        ret_obj.score = max_val;
        return ret_obj;
    }
    int betterValue = res[0].score;
    for(int i=0;i<res_win.size();i++) {
        betterValue = min(betterValue, res[i].score);
    }
    ret_obj.score = betterValue;
    return ret_obj;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = 0;
    for(int i=0;i<4;i++) {
        answer = max(answer, moveA(board, aloc, bloc, dxs[i], dys[i]));
    }
    return answer;
}