//https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(auto& iter : sizes){
        if(iter[0] < iter[1]){
            int k = iter[0];
            iter[0] = iter[1];
            iter[1] = k;
        }
    }
    int w = 0; int h = 0;
    for(auto& iter : sizes){
        if(w < iter[0]) w = iter[0];
        if(h < iter[1]) h = iter[1];
    }
    answer = w * h;
    return answer;
}
