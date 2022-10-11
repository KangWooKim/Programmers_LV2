// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(auto& number : numbers){
        string s = to_string(number);
        v.push_back(s);
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(auto& c : v){
        answer = answer + c;
    }
    if(answer[0] == '0' && stoi(answer) == 0) return "0";
    return answer;
}
