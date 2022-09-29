#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> profitMap;
map<string, string> bossMap;

void traceProfit(string &seller, int &money) {
    int tax = money/10;
    int profit = money - tax;
    profitMap[seller] += profit;
    if(bossMap[seller]=="-") return;
    if(tax>0) traceProfit(bossMap[seller], tax);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;    
    for(int i=0;i<enroll.size();i++) {
        bossMap[enroll[i]] = referral[i];
        profitMap[enroll[i]] = 0;
    }
    
    int price = 0;
    for(int i=0;i<seller.size();i++) {
        price = 100*amount[i];
        traceProfit(seller[i], price);
    }
    
    for(const auto &employee: enroll) answer.push_back(profitMap[employee]);
    return answer;
}