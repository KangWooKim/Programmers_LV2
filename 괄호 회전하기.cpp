// https://programmers.co.kr/learn/courses/30/lessons/76502#

#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.size();
    vector<string> list;
    string s1(s);
    for(int i = 0 ; i < s1.size() ; i++){
        if(i > 0){
            string s2 = s1.substr(0, 1);
            s1.erase(0, 1);
            s1 += s2;
            
        }
        for(int j = 0 ; j < s1.size() ; j++){
            string l = s1.substr(j, 1);
            if(l == "[" || l == "{" || l == "("){
                list.push_back(l);
            }
            if(list.empty()){answer--; break;}
            string a = list.back();
            if(l == "]"){
                if(a == "["){list.pop_back();}
                else{answer--; break;}
            }
            if(l == ")"){
                if(a == "("){list.pop_back();}
                else{answer--; break;}
            }
            if(l == "}"){
                if(a == "{"){list.pop_back();}
                else{answer--; break;}
            }
            if(j == s1.size() - 1 && !list.empty()){
                answer--; break;
            }
        }
        list.clear();
    }
    return answer;
}
