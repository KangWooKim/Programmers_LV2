// https://school.programmers.co.kr/learn/courses/30/lessons/72412

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> mp;
    vector<string> keylist;
    for(int i = 0 ; i < info.size() ; i++){
        stringstream in(info[i]);
        vector<string> vec; string s;
        while(in >> s){vec.push_back(s);}
        for(int k = 0 ; k <= 4 ; k++){
            vector<bool> b(4, false);
            for(int q = 0 ; q < k ; q++){
                b[q] = true;
            }
            sort(b.begin(), b.end());
            do{
                string s1 = "";
                for(int j = 0 ; j < b.size() ; j++){
                    if(!b[j]) s1.append(vec[j]);
                    else if(b[j]) s1.append("-");
                }
                int score = stoi(vec.back());
                mp[s1].push_back(score);
                keylist.push_back(s1);
            }while(next_permutation(b.begin(), b.end()));
        }
    }
    
    
    for(int i = 0 ; i < query.size() ; i++){
        string s1 = ""; string s2 = ""; string s = "";
        stringstream in(query[i]);
        while(in >> s){
            if(s == "and") continue;
            else if(isdigit(s[0])){s2 = s; break;}
            else{s1.append(s);}
        }
        int score = stoi(s2);
        vector<int> vec = mp[s1];
        int num = 0;
        
        for(int k = 0 ; k < vec.size() ; k++){
            if(vec[k] >= score){
                num++;
                
            }
        }
        answer.push_back(num);
    }
    
    return answer;
}
