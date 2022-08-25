// https://school.programmers.co.kr/learn/courses/30/lessons/72411

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto & i : orders)
        sort(i.begin(), i.end());
    
    map<string, int> mp;
    for(auto order : orders){
        
        for(auto c : course){
            if(c > order.length()) continue;
            vector<bool> vec(order.length(), true);
            for(int i = 0 ; i < order.length() - c ; i++){vec[i] = false;}
            do{
                string s = "";
                for(int i = 0 ; i < vec.size() ; i++){
                    if(vec[i]) s += order[i];
                }
                mp[s]++;
            }while(next_permutation(vec.begin(), vec.end()));
        }
    }
    
    vector<pair<string, int>> list;
    for(auto c : mp){
        if(c.second > 1) list.push_back(make_pair(c.first, c.second));
    }
    sort(list.begin(), list.end(), cmp);
    
    for(auto i : course){
        int maxx = 0;
        for(auto m : list){
            if(m.first.length() != i) continue;
            else if(maxx == 0){
                maxx = m.second;
                answer.push_back(m.first);
            }
            else if(maxx == m.second){
                answer.push_back(m.first);
            }
            else
                break;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
