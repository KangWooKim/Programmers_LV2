// https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0 ; i < scoville.size() ; i++){
        q.push(scoville[i]);
    }
    while(q.top() < K && q.size() != 1){
        int i1 = q.top(); q.pop();
        int i2 = q.top(); q.pop();
        q.push(i1 + i2 * 2);
        answer++;
    }
    if(q.size() == 1 && q.top() < K) answer = -1;
    return answer;
}
