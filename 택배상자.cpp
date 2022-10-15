// https://school.programmers.co.kr/learn/courses/30/lessons/131704#

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    reverse(order.begin(), order.end());
    int now = 1;
    vector<int> con;
    while(!order.empty()){
        if(order.back() == now){
            order.pop_back();
            ++answer;
            ++now;
            continue;
        }
        if(!con.empty() && con.back() == order.back()){
            ++answer;
            con.pop_back(); order.pop_back();
            continue;
        }
        if(now < order.back()){
            con.push_back(now++);
            continue;
        }
        if(!con.empty() && con.back() > order.back() && now > order.back()){
            return answer;
        }
        
    }
    return answer;
}
