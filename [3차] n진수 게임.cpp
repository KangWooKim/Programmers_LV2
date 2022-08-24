// https://school.programmers.co.kr/learn/courses/30/lessons/17687

#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> numberList = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string s = "0"; int now = 0;
    while(s.length() < t * m){
        ++now;
        int k = now;
        string s1 = "";
        while(k != 0){
            char c = numberList[k % n];
            s1 += c;
            k /= n;
        }
        reverse(s1.begin(), s1.end());
        s.append(s1);
    }
    int idx = 0;
    while(answer.length() != t){
        answer += s[p + (m * idx) - 1];
        idx++;
    }
    return answer;
}

