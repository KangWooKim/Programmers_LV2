// https://school.programmers.co.kr/learn/courses/30/lessons/155651

#include <bits/stdc++.h>
using namespace std;

int calculateTime(string time){
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int t = hour * 60 + minute;
    return t;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> list;
    int last = calculateTime("23:59");
    for(auto& b : book_time){
        int start = calculateTime(b[0]);
        int end = calculateTime(b[1]) + 10;
        if(end >= last) end = last;
        list.push_back({start, end});
    }
    for(int time = 0 ; time <= last ; time++){
        int hotel = 0;
        for(int i = 0 ; i < list.size() ; i++){
            if(time >= list[i][0] && time < list[i][1]){
                hotel++;
            }
        }
        answer = answer > hotel ? answer : hotel;
    }
    
    return answer;
}
