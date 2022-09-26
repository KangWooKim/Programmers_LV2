// https://school.programmers.co.kr/learn/courses/30/lessons/70129

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void to_binary(string& s){
    int l = s.length();
    s = "";
    while(l != 0){
        s += (l % 2 == 0 ? "0" : "1");
        l = l / 2;
    }
    
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while(s != "1"){
        int cnt = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '1') cnt++;
            else if(s[i] == '0') answer[1]++;
        }
        s = "";
        for(int i = 0 ; i < cnt ; i++) s += "1";
        to_binary(s);
        answer[0]++;
    }
    return answer;
}
