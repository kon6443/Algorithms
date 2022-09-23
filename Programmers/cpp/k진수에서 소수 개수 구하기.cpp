#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string convertNtoBase(int decimal, int &base) {
    if(decimal == 0) return "0";
    char chars[] = "0123456789ABCDEF"; // Characters that may be used
    string result = "";
    do{
        result.push_back(chars[decimal%base]);
        decimal /= base;
    } while(decimal != 0);
    return string(result.rbegin(), result.rend());
}

bool isPrime(long long n) {
    if(n==1) return false;
    for(long long i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}

vector<string> split(string &s, char delimiter) {
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

int solution(int n, int k) {
    int answer = 0;
    string convertedNum = convertNtoBase(n, k);
    vector<string> splitedNum = split(convertedNum, '0');
    for(const auto &item: splitedNum) if(isPrime(stoll(item))) answer ++;
    return answer;
}


