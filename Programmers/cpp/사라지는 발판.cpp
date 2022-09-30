#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> dxs = {1, 0, -1, 0};
vector<int> dys = {0, 1, 0, -1};
int moveA(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy);
int moveB(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy);

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
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool flag = true;
    for(int i=0;i<4;i++) {
        if(0>=cursor[0]+dx[i] || cursor[0]+dx[i]>=board.size()) continue;
        if(0>=cursor[1]+dy[i] || cursor[1]+dy[i]>=board[0].size()) continue;
        if(board[cursor[0]+dx[i]][cursor[1]+dy[i]]==1) {
            flag = false;
            break;
        }
    }
    return flag;
}

int moveB(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy) {
    if(isStuck(board, bloc)) return 0;
    
    if(board[bloc[0]+dx][bloc[1]+dy]==0) return 0;
    if(isCursorOutside(board, bloc[0]+dx, bloc[1]+dy)) return 0;
    board[bloc[0]][bloc[1]] = 0;
    bloc[0] += dx;
    bloc[1] += dy;
    if(checkSinkhole(board, aloc)) return 1;
    
    int betterValue = 0;
    for(int i=0;i<4;i++) {
        dx = dxs[i];
        dy = dys[i];
        betterValue += max(betterValue, moveA(board, aloc, bloc, dx, dy));
    }
    return betterValue+1;
}

int moveA(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int dx, int dy) {
    if(isStuck(board, aloc)) return 0;
    
    if(board[aloc[0]+dx][aloc[1]+dy]==0) return 0;
    if(isCursorOutside(board, aloc[0]+dx, aloc[1]+dy)) return 0;
    board[aloc[0]][aloc[1]] = 0;
    aloc[0] += dx;
    aloc[1] += dy;
    if(checkSinkhole(board, bloc)) return 1;
    
    int betterValue = 0;
    for(int i=0;i<4;i++) {
        dx = dxs[i];
        dy = dys[i];
        betterValue += max(betterValue, moveB(board, aloc, bloc, dx, dy));
    }
    return betterValue+1;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = 0;
    int dx, dy;
    for(int i=0;i<4;i++) {
        dx = dxs[i];
        dy = dys[i];
        answer += max(answer, moveA(board, aloc, bloc, dx, dy));
    }
    return answer;
}