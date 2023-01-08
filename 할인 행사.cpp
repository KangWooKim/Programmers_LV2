// https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool check_answer(vector<string> want, vector<int> number, unordered_map<string, int> mp){
    for(int i = 0 ; i < want.size() ; i++){
        if(mp[want[i]] < number[i]) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> mp;
    for(int i = 0 ; i < 10 ; i++){
        mp[discount[i]]++;
    }
    
    if(check_answer(want, number, mp)) ++answer;
    
    for(int i = 1 ; i < discount.size() - 9 ; i++){
        mp[discount[i - 1]]--;
        mp[discount[i + 9]]++;
        if(check_answer(want, number, mp)) ++answer;
    }
    
    return answer;
}
