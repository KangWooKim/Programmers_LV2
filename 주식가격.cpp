// https://school.programmers.co.kr/learn/courses/30/lessons/42584

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<pair<int, int>> v;
    v.push_back(make_pair(prices[0], 0));
    
    for(int i = 1; i < prices.size() ; i++){
        int priceA = v.back().first;
        int priceB = prices[i];
        
        while(!v.empty() && priceA > priceB){
            answer[v.back().second] = i - v.back().second;
            v.pop_back();
            priceA = v.back().first;
        }
        
        v.push_back(make_pair(priceB, i));
    }
    
    while(!v.empty()){
        int idx = v.back().second;
        answer[idx] = prices.size() - idx - 1;
        v.pop_back();
    }
    return answer;
}
