// https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i = 0 ; i < progresses.size() ; i++){
        int res = 100 - progresses[i];
        int day = (res % speeds[i] == 0 ? (res / speeds[i]) : (res / speeds[i] + 1));
        days.push_back(day);
    }
    reverse(days.begin(), days.end());
    while(!days.empty()){
        int i = days.back();
        int cnt = 0;
        while(!days.empty() && days.back() <= i){
            days.pop_back(); ++cnt;
        }
        answer.push_back(cnt);
    }
    return answer;
}
