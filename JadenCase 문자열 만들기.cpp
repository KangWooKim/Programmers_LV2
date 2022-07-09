// https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    s[0] = toupper(s[0]);
    for(int i = 1 ; i < s.length() ; i++){
        if(s[i - 1] == ' ') s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    return s;
}
