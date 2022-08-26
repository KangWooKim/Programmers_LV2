// https://school.programmers.co.kr/learn/courses/30/lessons/17686

#include <bits/stdc++.h>

using namespace std;

vector<string> a;

bool cmp(string s1, string s2){
    string s1head, s2head, s1number, s2number = "";
    int s1idx = find(a.begin(), a.end(), s1) - a.begin();
    int s2idx = find(a.begin(), a.end(), s2) - a.begin();
    for(auto c : s1){
        if(isdigit(c)) break;
        s1head += c;
    }
    for(auto c : s2){
        if(isdigit(c)) break;
        s2head += c;
    }
    for(int i = s1head.length() ; i < s1.length() ; i++){
        if(isdigit(s1[i])) s1number += s1[i];
        else break;
    }
    for(int i = s2head.length() ; i< s2.length() ; i++){
        if(isdigit(s2[i])) s2number += s2[i];
        else break;
    }
    for(auto& c : s1head) c = tolower(c);
    for(auto& c : s2head) c = tolower(c);
    
    if(stoi(s1number) == stoi(s2number) && s1head == s2head)
        return s1idx < s2idx;
    else if(s1head == s2head)
        return stoi(s1number) < stoi(s2number);
    else
        return s1head < s2head;
}


vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    a = files;
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}
