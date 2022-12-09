// https://school.programmers.co.kr/learn/courses/30/lessons/142085?language=cpp

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> pq;
    int res = 0; 
    
    for(int i = 0 ; i < enemy.size() ; i++){
        res += enemy[i];
        if(res <= n){
            pq.push(enemy[i]);
            answer += 1;
        }
        else if(k > 0){
            k -= 1;
            pq.push(enemy[i]);
            res -= pq.top();
            pq.pop();
            answer += 1;
        }
        else
            break;
    }
    return answer;
}
