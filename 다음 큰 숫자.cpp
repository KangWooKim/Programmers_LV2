// https://school.programmers.co.kr/learn/courses/30/lessons/12911

#include <bits/stdc++.h>

using namespace std;

int count(string s){
    int cnt = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1') cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    bitset<200> bit(n);
    string s1 = bit.to_string();
    s1 = s1.substr(s1.find('1'));
    int n_cnt = count(s1);
    int next = n;
    while(true){
        ++next;
        bitset<200> bit1(next);
        string s2 = bit1.to_string();
        s2 = s2.substr(s2.find('1'));
        int next_cnt = count(s2);
        if(n_cnt == next_cnt) break;
    }
    return next;
}
