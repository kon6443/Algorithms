#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long countIntegerInDistance(double &l, double &s) {
    return floor(l) - ceil(s) + 1;
}

double getYCoordinate(int &r, int &x) {
    if(r<x) return 0;
    return sqrt((long long)r*r - (long long)x*x);
}

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int x=1;x<=r2;x++) {
        double l = getYCoordinate(r2,x);
        double s = getYCoordinate(r1,x);
        answer += countIntegerInDistance(l,s);
    }
    answer = 4*answer;
    return answer;
}

