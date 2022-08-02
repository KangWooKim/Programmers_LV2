// https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> idx;
    for(int i = 0 ; i < skill_trees.size() ; i++){
        idx.clear();
        for(int j = 0 ; j < skill.length() ; j++){
            if(skill_trees[i].find(skill[j]) != string::npos){
                int a = skill_trees[i].find(skill[j]);
                idx.push_back(a);
            }
            else
                idx.push_back(99);
            }
        vector<int> v = idx;
        sort(v.begin(), v.end());
        if(idx == v) answer++;
    }
    return answer;
}
