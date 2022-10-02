// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i = 0 ; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
    }
    stable_sort(priorities.begin(), priorities.end());
    while(!priorities.empty()){
        int idx = q.front().first;
        int priority = q.front().second;
        if(idx == location && priority == priorities.back()){
            return answer + 1;
        }
        if(priority == priorities.back()){
            ++answer;
            priorities.pop_back(); q.pop();
        }
        else{
            auto p = q.front();
            q.pop(); q.push(p);
        }
    }
    return answer;
}
