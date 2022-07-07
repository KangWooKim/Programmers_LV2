// https://school.programmers.co.kr/learn/courses/30/lessons/92335

#include <bits/stdc++.h>

using namespace std;

bool prime(string s){
    long long val = stol(s);
    if(val == 1) return false;
    if(val == 2) return true;
    else{
        for(int i = 2 ; i < sqrt(val) + 1 ; i++){
            if(val % i == 0) return false;
        }
    }
    return true;
}

string change(int n, int k){
    int a = n; int b; string val;
    while(true){
        b = a % k;
        a = a / k;
        val += to_string(b);
        if(a < k && a != 0){
            val += to_string(a); break;
        }
        if(a == 0) break;
    }
    reverse(val.begin(), val.end());
    val = regex_replace(val, regex("0"), " ");
    return val;
}

int solution(int n, int k) {
    int answer = 0;
    string s = change(n, k);
    stringstream in(s);
    string s1;
    while(in >> s1){
        if(prime(s1)) answer++;
    }
    
    return answer;
}
