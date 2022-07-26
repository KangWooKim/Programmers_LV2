// https://school.programmers.co.kr/learn/courses/30/lessons/62048

#include <bits/stdc++.h>
using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w * h; long long sum = w + h;
    long long res = w % h;
    
    
    while(res != 0){
        w = h;
        h = res;
        res = w % h;
    }
    answer = answer - sum + h;
    return answer;
}
