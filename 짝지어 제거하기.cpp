//https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    vector<char> c;
    c.push_back(s[0]);
    for(int i = 1 ; i < s.length() ; i++){
        if(s[i] == c.back()){
            c.pop_back();
        }
        else if(s[i] != c.back()){
            c.push_back(s[i]);
        }
    }
    if(c.empty()) return 1;
    else return 0;
}
