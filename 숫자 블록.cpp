// https://school.programmers.co.kr/learn/courses/30/lessons/12923

#include <bits/stdc++.h>

using namespace std;

long long divide(long long number){
    if(number == 1) return 0;
    for(long long i = 2 ; i < sqrt(number) + 1 ; i++){
        long long val = number / i;
        if(val > 10000000) continue;
        if(number % i == 0) return val;
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i = begin ; i <= end ; i++){
        long long val = divide(i);
        answer.push_back((int)val);
    }
    return answer;
}
