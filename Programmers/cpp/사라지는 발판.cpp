#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m;
bool attendance[5][5];
vector<vector<int>> panel;
vector<int> dxs = {1, 0, -1, 0};
vector<int> dys = {0, 1, 0, -1};

bool isCursorOutside(int &x, int &y) {
    return (0>x || x>=n || 0>y || y>=m);
}

int move(int curx, int cury, int opox, int opoy) {
    if(attendance[curx][cury]) return 0;
    int ret = 0;    
    for(int i=0;i<4;i++) {
        int nx = curx + dxs[i];
        int ny = cury + dys[i];
        if(isCursorOutside(nx, ny) || attendance[nx][ny] || !panel[nx][ny])
            continue;
        attendance[curx][cury] = 1;
        int val = move(opox, opoy, nx, ny) + 1;
        attendance[curx][cury] = 0;

        /* even remainder means win, odd remainder means lose. */
        // losing but next turn might have a chance to win. 
        if(ret%2==0 && val%2==1) ret = val;
        // losing and next turn is also losing, but we are taking a better way.
        else if(ret%2==0 && val%2==0) ret = max(ret, val);
        // winning and next turn also winning, but better way.
        else if(ret%2==1 && val%2==1) ret = min(ret, val);
        // we are not choosing a case that we are winning but next turn is losing.
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    panel = board;
    return move(aloc[0], aloc[1], bloc[0], bloc[1]);
}