// https://school.programmers.co.kr/learn/courses/30/lessons/140107

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    
    for(int i = 0 ; i <= d ; i += k){
        long long val = sqrt(((long long)d * d) - ((long long)i * i));
        if(val == 0) break;
        answer += (val / k);
        
    }
    answer += d / k;
    return ++answer;
}
