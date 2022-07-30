//https://school.programmers.co.kr/learn/courses/30/lessons/12900

#include <bits/stdc++.h>

using namespace std;



int solution(int n) {
    int answer = 0;
    vector<int> vec;
    vec.push_back(1); vec.push_back(2);
    for(int i = 2 ; i < 60000 ; i++){
        vec.push_back((vec[vec.size() - 1] + vec[vec.size() - 2]) % 1000000007);
    }
    answer = vec[n - 1] % 1000000007;
    return answer;
}
