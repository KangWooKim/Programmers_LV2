// https://programmers.co.kr/learn/courses/30/lessons/64065

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> list = {"1","2","3","4","5","6","7","8","9","0"};
    vector<pair<int, int>> count1;
    unordered_multiset<int> set1;
    string str = s;
    string number = "";
    for(int i = 0 ; i < str.length() ; i++){
        string s1 = str.substr(i, 1);
        if(find(list.begin(), list.end(), s1) != list.end())
            number += s1;
        else if(number != ""){
            if(set1.count(stoi(number)) == 0)
                count1.push_back(make_pair(1, stoi(number)));
            set1.insert(stoi(number));
            number = "";
        }
        else
            continue;
    }
    for(int i = 0 ; i < count1.size() ; i++){
        count1[i].first = set1.count(count1[i].second);
    }
    sort(count1.begin(), count1.end(), cmp);
    for(int i = 0 ; i < count1.size() ; i++){
        answer.push_back(count1[i].second);
    }
    return answer;
}
