// https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    stable_sort(citations.begin(), citations.end());
    for(int i = citations.size() ; i >= 0 ; i--){
        if(citations[citations.size() - i] >= i) return i;
    }
    return answer;
}
