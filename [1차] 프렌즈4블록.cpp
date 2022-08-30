// https://school.programmers.co.kr/learn/courses/30/lessons/17679

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, bool> p1, pair<char, bool> p2){
    return p1.second < p2.second;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<pair<char, bool>>> vec(n);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = m - 1 ; j >= 0 ; j--){
            vec[i].push_back({board[j][i], false});
        }
    }
    
    while(true){
        int res = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = m - 2 ; j > -1 ; j--){
                char c = vec[i][j].first; if(c == ' ') continue;
                if(vec[i + 1][j].first == c && vec[i][j + 1].first == c && vec[i + 1][j + 1].first == c){
                    vec[i + 1][j].second = true;
                    vec[i][j + 1].second = true;
                    vec[i + 1][j + 1].second = true;
                    vec[i][j].second = true;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = m -1 ; j > -1 ; j--){
                if(vec[i][j].second && vec[i][j].first != ' ') {vec[i][j].first = ' '; res++;}
            }
        }
        for(int i = 0 ; i < n ; i++)
            stable_sort(vec[i].begin(), vec[i].end(), cmp);
        
        if(res == 0) break;
        answer += res;
    }
    
    return answer;
}
