// https://school.programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<pair<int, int>> v;
    v.push_back({0, prices[0]});
    
    for(int i = 1 ; i < prices.size() ; i++){
        while(v.back().second > prices[i]){
            answer[v.back().first] = i - v.back().first;
            v.pop_back();
        }
        v.push_back({i, prices[i]});
    }
    for(int i = 0 ; i < answer.size() - 1; i++){
        if(answer[i] == 0){
            answer[i] = prices.size() - i - 1;
        }
    }
    
    return answer;
}
