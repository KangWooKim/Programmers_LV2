// https://school.programmers.co.kr/learn/courses/30/lessons/12936

#include <bits/stdc++.h>

using namespace std;

long long factorial(int n){
    long long val = 1;
    for(int i = 1 ; i < n + 1 ; i++){
        val *= i;
    }
    return val;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> list;
    for(int i = 0 ; i < n + 1 ; i++){
        list.push_back(i);
    }
    for(int i = 1 ; i < n + 1 ; i++){
        long long index = (k + factorial(n - i) - 1) / factorial(n - i);
        answer.push_back(list[index]);
        list.erase(list.begin() + index);
        k = k - (index - 1) * factorial(n - i);
    }
    return answer;
}
