// https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
set<int> s;
vector<bool> prime(10000000, true);

void make_prime(){
    prime[1] = false; prime[0] = false;
    for(int i = 2 ; i < prime.size() ; i++){
        if(prime[i]){
            for(int j = 2 * i ; j < prime.size() ; j += i){
                prime[j] = false;
            }
        }
    }
}

void make_set(string s1, string s2){
    if(s1 != ""){
        s.insert(stoi(s1));
    }
    for(int i = 0 ; i < s2.length() ; i++){
        make_set(s1 + s2[i], s2.substr(0, i) + s2.substr(i + 1));
    }
}

int solution(string numbers) {
    make_prime();
    make_set("", numbers);
    int cnt = 0;
    for(auto& number : s){
        if(prime[number]) cnt++;
    }
    return cnt;
}
