// https://school.programmers.co.kr/learn/courses/30/lessons/181188?language=cpp

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    stable_sort(targets.begin(), targets.end(), [](const auto &a, const auto & b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    });
    int start = targets[0][0];
    int end = targets[0][1];
    ++answer;
    for(auto& target : targets){
        if(target[0] < end && target[1] >= end) continue;
        else if(target[0] > start && target[1] < end){
            start = target[0];
            end = target[1];
            continue;
        }
        else if(target[0] >= end){
            ++answer;
            start = target[0];
            end = target[1];
        }
    }
    
    return answer;
}
