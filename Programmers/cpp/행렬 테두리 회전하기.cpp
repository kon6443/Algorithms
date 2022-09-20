#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print2DMatrix(vector<vector<int>> matrix) {
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[0].size();j++) {
            cout<<matrix[i][j]<<" ";
        } cout<<endl;
    }
}

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix, vector<int> query, vector<int> &answer) {
    int x1 = query[0]-1;
    int y1 = query[1]-1;
    int x2 = query[2]-1;
    int y2 = query[3]-1;
    int top_left = matrix[x1][y1];
    int minimum = top_left;
    for(int i=x1;i<x2;i++) {
        minimum = min(minimum, matrix[i][y1]);
        matrix[i][y1] = matrix[i+1][y1];
    }
    for(int i=y1;i<y2;i++) {
        minimum = min(minimum, matrix[x2][i]);
        matrix[x2][i] = matrix[x2][i+1];
    }
    for(int i=x2;i>x1;i--) {
        minimum = min(minimum, matrix[i][y2]);
        matrix[i][y2] = matrix[i-1][y2];
    }
    for(int i=y2;i>y1;i--) {
        minimum = min(minimum, matrix[x1][i]);
        matrix[x1][i] = matrix[x1][i-1];
    }
    matrix[x1][y1+1] = top_left;
    answer.push_back(minimum);
    return matrix;
}

vector<vector<int>> getInitialMatrix(int rows, int columns) {
    vector<vector<int>> matrix;
    int k=1;
    for(int i=0;i<rows;i++) {
        vector<int> v;
        for(int j=0;j<columns;j++) {
            v.push_back(k++);
        }
        matrix.push_back(v);
    }
    return matrix;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix = getInitialMatrix(rows, columns);
    for(int i=0;i<queries.size();i++) {
        vector<int> v;
        for(int j=0;j<queries[i].size();j++) v.push_back(queries[i][j]);
        matrix = rotateMatrix(matrix, v, answer);
    }
    return answer;
}