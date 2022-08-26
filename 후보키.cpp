// https://school.programmers.co.kr/learn/courses/30/lessons/42890#

#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2){
    return s1.length() < s2.length();
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<string> vec;
    
    for(int i = 1 ; i <= relation[0].size() ; i++){
        vector<bool> v(relation[0].size(), false);
        for(int j = 0 ; j < i ; j++){
            v[j] = true;
        }
        sort(v.begin(), v.end());
        do{
            string s = "";
            for(int i = 0 ; i < v.size() ; i++){
                if(v[i]) s += ('0' + i);
            }
            vec.push_back(s);
        }while(next_permutation(v.begin(), v.end()));    
    }
    stable_sort(vec.begin(), vec.end(), cmp);
    for(auto& s : vec){
        if(s == "None") continue;
        vector<vector<string>> v1;
        set<vector<string>> st;
        for(int i = 0 ; i < relation.size() ; i++){
            vector<string> v2;
            for(auto c : s){
                int idx = c - '0';
                v2.push_back(relation[i][idx]);
            }
            v1.push_back(v2); st.insert(v2);
        }
        if(v1.size() != st.size()) s = "None";
        else if(v1.size() == st.size()){
            for(auto& s1 : vec){
                if(s != s1){
                    bool a = true;
                    for(auto c : s){
                        if(s1.find(c) != string :: npos){continue;}
                        else {a = false; break;}
                    }
                    if(a) s1 = "None";
                }
            }
        }
        v1.clear(); st.clear();
    }
    for(auto s : vec){
        if(s != "None") answer++;
    }
    
    return answer;
}
