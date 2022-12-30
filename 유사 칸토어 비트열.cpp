//https://school.programmers.co.kr/learn/courses/30/lessons/148652?language=cpp#

#include <bits/stdc++.h>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    l--; r--;
    string s = "1"; string s1;
    long long d, left, right, cut;
    for(int i = 1 ; i <= n ; i++){
        s1 = "";
        for(auto& c : s){
            if(c == '1') s1 += "11011";
            else s1 += "00000";
        }
        s = s1;
        if(n == i){
            for(int q = l ; q <= r ; q++){
                if(s[q] == '1') ++answer;
            }
            break;
        }
        d = pow(5, n - i);
        left = l / d; right = r / d; cut = left * d;
        s = s.substr(left, right - left + 1);
        l -= cut;
        r -= cut;
    }
    
    return answer;
}
