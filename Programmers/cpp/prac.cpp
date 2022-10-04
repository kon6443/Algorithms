#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void foo(int &a);
void foo2(int a);
void pracMap();
void pracConvert();
template<typename T>
void printVector(vector<T> &v);
string getContinents(vector<string> &, int &, int &);
bool isCursorOut(int &, int &);

int n, m;
vector<vector<bool>> attendance;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    vector<string> worldMap;
    worldMap.push_back("AAB...DA");
    worldMap.push_back("ABB.C.AD");
    worldMap.push_back("AAB.C.DA");
    worldMap.push_back(".CC.C.AD");
    worldMap.push_back("C.....CC");
    worldMap.push_back("..DDD...");
    n = worldMap.size();
    m = worldMap[0].size();
    for(const auto &item: worldMap) cout<<item<<endl;
    attendance = vector<vector<bool>> (n, vector<bool>(m, false));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(worldMap[i][j]=='.') attendance[i][j] = true;
        }
    }
    vector<string> continents;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(attendance[i][j]) continue;
            else {
                string continent = getContinents(worldMap, i, j);
                sort(continent.begin(), continent.end());
                continents.push_back(continent);
            }
        }
    }
    for(int i=0;i<continents.size();i++) {
        cout<<i+1<<"th continent's size: "<<continents[i].size()<<", ";
        for(int j=0;j<continents[i].size();j++) {
            cout<<continents[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}

bool isCursorOut(int &x, int &y) {
    return x<0 || x>=n || y<0 || y>=m;
}

string getContinents(vector<string> &worldMap, int &x, int &y) {
    string continent = "";
    if(isCursorOut(x, y) || attendance[x][y]) return "";
    continent += worldMap[x][y];
    attendance[x][y] = true;
    for(int i=0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        continent += getContinents(worldMap, nx, ny);
    }
    return continent;
}

template<typename T>
void printVector(vector<T> &v) {
    for(const auto &item: v) cout<<item<<" ";
    cout<<endl;
}

void pracConvert() {
    int a = 20;
    string s = to_string(a);
    cout<<s<<endl;
}

void pracMap() {
    map<char, char> m;
    m['A'] = '1';
    m['B'] = '2';
    m['C'] = '3';
    cout<<m['A']<<endl;
    cout<<m['B']<<endl;
    cout<<m['C']<<endl;
}

void foo2(int a) {
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
}

void foo(int &a) {
    cout<<"a: "<<a<<endl;
    cout<<"&a: "<<&a<<endl;
}