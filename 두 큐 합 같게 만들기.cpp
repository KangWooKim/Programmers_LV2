// https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    queue<int> q1, q2;
    for(int i = 0 ; i < queue1.size() ; i++){
        q1.push(queue1[i]); q2.push(queue2[i]);
    }
    while(true){
        if(answer > queue1.size() + queue2.size() + 2){answer = -1; break;}
        else if(sum1 > sum2){int res = q1.front(); q1.pop(); q2.push(res); sum1 -= res; sum2 += res; answer++;}
        else if(sum1 < sum2){int res = q2.front(); q2.pop(); q1.push(res); sum1 += res; sum2 -= res; answer++;}
        if(sum1 == sum2) break;
    }
    return answer;
}
