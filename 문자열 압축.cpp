// https://school.programmers.co.kr/learn/courses/30/lessons/60057

#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i = 1 ; i <= s.length() ; i++){
        string s1 = s.substr(0, i); string s0 = ""; int cnt = 1; string s2 = "";
        for(int j = i ; j < s.length() ; j++){
            s2 += s[j];
            if(s1.length() == s2.length()){
                if(s1 == s2){
                    cnt++;
                    s2 = "";
                }
                else if(s1 != s2){
                    if(cnt != 1) s0.append(to_string(cnt).append(s1));
                    else s0.append(s1);
                    s1 = s2;
                    s2 = "";
                    cnt = 1;
                }
            }
            if(j == s.length() - 1 && s1 != s2){
                if(cnt != 1) s0.append(to_string(cnt).append(s1));
                else s0.append(s1);
                s0.append(s2);
            }
        }
        if(answer > s0.length() && s0.length() != 0) answer = s0.length();
    }
    return answer;
}
