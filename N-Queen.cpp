// https://school.programmers.co.kr/learn/courses/30/lessons/12952

#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    for(int i = 0 ; i < n ; i++) v.push_back(i);
    do{
        bool res = true;
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = i + 1 ; j < v.size() ; j++){
                if(abs(i - j) == abs(v[i] - v[j])) res = false;
                if(!res) break;
            }
            if(!res) break;
        }
        if(res) answer++;
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}
