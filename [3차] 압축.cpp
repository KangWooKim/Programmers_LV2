// https://school.programmers.co.kr/learn/courses/30/lessons/17684

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dic;
    for(int i = 0 ; i < 26 ; i++){
        string s = ""; char a = 'A' + i; s += a;
        dic.push_back(s);
    }
    
    int point = 0;
    int l = 1;
    int idx = 0;
    
    while(true){
        string s = msg.substr(point, l);
        if(find(dic.begin(), dic.end(), s) != dic.end()){
            l++; idx = find(dic.begin(), dic.end(), s) - dic.begin();
            if(point + l - 1 == msg.length()){
                answer.push_back(idx + 1);
                break;
            }
            continue;
        }
        if(find(dic.begin(), dic.end(), s) == dic.end()){
            dic.push_back(s);
            answer.push_back(idx + 1);
            point = point + l - 1;
            l = 1;
        }
        
    }
    return answer;
}
