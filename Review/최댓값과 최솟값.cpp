// https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;
    stringstream in(s); string s1;
    while(in >> s1){
        int i = stoi(s1);
        pq1.push(i);
        pq2.push(i);
    }
    answer += (to_string(pq1.top()) + " " + to_string(pq2.top()));
    return answer;
}
