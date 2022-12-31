// https://school.programmers.co.kr/learn/courses/30/lessons/132265

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> b1, b2;
    for(auto& t : topping)
        b2[t]++;
    
    for(int i = 0 ; i < topping.size() - 1 ; i++){
        b1[topping[i]]++;
        b2[topping[i]]--;
        if(b2[topping[i]] == 0)
            b2.erase(topping[i]);
        if(b1.size() == b2.size()) answer++;
    }
    
    return answer;
}
