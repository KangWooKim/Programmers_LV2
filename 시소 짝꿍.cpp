// https://school.programmers.co.kr/learn/courses/30/lessons/152996

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<int> v(1000 * 4 + 1, 0);
    vector<int> num(1001, 0);
    
    for(auto& w : weights){
        num[w]++;
        v[w * 2]++;
        v[w * 3]++;
        v[w * 4]++;
    }
    for(auto& i : v){
        if(i == 0) continue;
        long long a = ((long long)i - 1) * (long long)i / 2;
        answer += a;
    }
    for(auto& i : num){
        if(i == 0) continue;
        long long a = ((long long)i - 1) * (long long)i / 2;
        answer -= 2 * a;
    }
    
    return answer;
}
