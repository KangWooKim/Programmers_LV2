// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> changes;
    for(const auto& i : clothes){
        changes[i[1]]++;
    }
    for(const auto& i : changes){
        
        answer *= (i.second + 1);
    }
    answer++;
    return answer;
}
