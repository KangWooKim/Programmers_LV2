#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> list;
    for(int i = 0 ; i < records.size() ; i++){
        stringstream in1(records[i]);
        string s1, s2, s3;
        in1 >> s1 >> s2 >> s3;
        if(find(list.begin(), list.end(), make_pair(s2, 0)) == list.end()){
            list.push_back(make_pair(s2, 0));
        }
    }
    
    for(int i = 0 ; i < records.size() ; i++){
        stringstream in(records[i]);
        string s1, s2, s3; in >> s1 >> s2 >> s3;
        int time = stoi(s1.substr(0, 2)) * 60 + stoi(s1.substr(3, 2));
        if(s3 == "IN"){
            for(int k = 0 ; k < list.size() ; k++){
                if(list[k].first == s2){ list[k].second -= time; break;}
            }
        }
        if(s3 == "OUT"){
            for(int k = 0 ; k < list.size() ; k++){
                if(list[k].first == s2){ list[k].second += time; break;}
            }
        }
    }
    sort(list.begin(), list.end());
    for(int k = 0 ; k < list.size() ; k++){
        if(list[k].second <= 0) list[k].second = list[k].second + (23 * 60 + 59);
        if(list[k].second <= fees[0]){ answer.push_back(fees[1]); continue;}
        
        (list[k].second - fees[0]) % fees[2] == 0 ? answer.push_back(fees[1] + (list[k].second - fees[0]) / fees[2] * fees[3]) : 
        answer.push_back(fees[1] + (((list[k].second - fees[0]) / fees[2]) + 1) * fees[3]);
        
    }
    return answer;
}
