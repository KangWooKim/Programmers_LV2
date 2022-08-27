// https://school.programmers.co.kr/learn/courses/30/lessons/81302

#include <bits/stdc++.h>

using namespace std;

bool check(vector<string> vec){
    vector<int> mx = {0, 0, 1, -1};
    vector<int> my = {1, -1, 0, 0};
    vector<int> mmx = {-2, 2, 0, 0, 1, 1, -1, -1};
    vector<int> mmy = {0, 0, -2, 2, 1, -1, 1, -1};
    for(int i = 0 ; i < vec.size() ; i++){
        
        for(int j = 0 ; j < vec[i].length() ; j++){
            
            char c1 = vec[i][j];
            
            if(c1 == 'X' || c1 == 'O') continue;
            
            for(int idx = 0 ; idx < mx.size() ; idx++){
                int nx = j + mx[idx]; int ny = i + my[idx];
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                char c2 = vec[ny][nx];
                if(c2 == 'P') return false;
            }
            
            for(int idx = 0 ; idx < 4 ; idx++){
                int nx = j + mmx[idx]; int ny = mmy[idx] + i;
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                char c2 = vec[ny][nx]; char c3 = vec[(i + ny) / 2][(j + nx) / 2];
                if(c2 == 'P' && c3 != 'X') return false;
            }
            
            for(int idx = 4 ; idx < mmx.size() ; idx++){
                int nx = j + mmx[idx]; int ny = mmy[idx] + i;
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                char c2 = vec[ny][nx]; char c3 = vec[ny][j]; char c4 = vec[i][nx];
                if(c2 == 'P'){
                    if(c3 != 'X' || c4 != 'X') return false;
                }
            }
        }
    }
    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto c : places){
        if(check(c)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}
