// https://school.programmers.co.kr/learn/courses/30/lessons/148653#

#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int l = log10(storey) + 1;
    vector<int> v(1, 0);
    for(int i = l - 1 ; i >= 0 ; i--){
        int k = pow(10, i);
        v.push_back(storey / k);
        storey %= k;
    }
    for(int i = v.size() - 1 ; i > 0 ; i--){
        if(v[i] == 10){
            v[i - 1]++;
            continue;
        }
        if(v[i] > 5){
            answer += (10 - v[i]);
            v[i - 1]++;
        }
        else if(v[i] < 5){
            answer += v[i];
        }
        else if(v[i] == 5){
            if(v[i - 1] >= 5){
                answer += (10 - v[i]);
                v[i - 1]++;
            }
            else{
                answer += v[i];
            }
        }
    }
    
    return answer + v[0];
}
