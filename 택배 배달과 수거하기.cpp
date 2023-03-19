// https://school.programmers.co.kr/learn/courses/30/lessons/150369

#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    for(int i = n - 1 ; i > -1 ; i--){
        while(deliveries[i] > 0 || pickups[i] > 0){
            answer = answer + 2 * (i + 1);
            deliveries[i] -= cap;
            pickups[i] -= cap;
        }
        
        if(i == 0) break;
        
        if(deliveries[i] < 0) deliveries[i - 1] += deliveries[i];
        if(pickups[i] < 0) pickups[i - 1] += pickups[i];
    }
    
    return answer;
}
