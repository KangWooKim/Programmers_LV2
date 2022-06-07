// https://programmers.co.kr/learn/courses/30/lessons/42888

#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> list;
    for(int i = 0 ; i < record.size() ; i++){
        stringstream in(record[i]);
        string a, b, c; in >> a >> b >> c;
        if(a == "Change" || a == "Enter"){
            if(list.count(b) == 0) list.insert({b, c});
            else list[b] = c;
        }
    }
    
    for(const auto& k : record){
        stringstream in(k);
        string a, b, c; in >> a >> b >> c;
        if(a == "Enter"){
            string s = list[b] + "님이 들어왔습니다.";
            answer.push_back(s);
        }
        else if(a == "Leave"){
            string s = list[b] + "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}
