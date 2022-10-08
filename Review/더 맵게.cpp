// https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto& s : scoville)
        pq.push(s);

    while(pq.size() > 1 && pq.top() < K){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b + b);
        ++answer;
    }
    if(pq.top() < K) return -1;
    return answer;
}
