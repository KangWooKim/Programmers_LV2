// https://school.programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    for(auto& c : clothes){
        mp[c[1]]++;
    }
    auto iter = mp.begin();
    while(iter != mp.end()){
        answer *= (iter->second + 1);
        ++iter;
    }
    return --answer;
}
