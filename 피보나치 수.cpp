// https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    vector<int> v(100002, 0);
    v[1] = 1;
    for(int i = 2 ; i < n + 1 ; i++){
        v[i] = (v[i - 1] + v[i - 2]) % 1234567;
    }
    return v[n];
}
