// https://school.programmers.co.kr/learn/courses/30/lessons/131701

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> v = elements;
    for(auto& e : elements)
        v.push_back(e);
    int len = 1;
    vector<int> s;
    while(len < elements.size() + 1){
        for(int i = 0 ; i < elements.size() ; i++){
            int sum = accumulate(v.begin() + i, v.begin() + i + len, 0);
            s.push_back(sum);
        }
        ++len;
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    return s.size();
}
