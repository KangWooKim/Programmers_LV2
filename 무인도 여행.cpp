// https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    vector<vector<bool>> v(maps.size(), vector<bool>(maps[0].length(), false));
    vector<int> nx = {1, -1, 0, 0};
    vector<int> ny = {0, 0, 1, -1};
    for(int y = 0 ; y < maps.size() ; y++){
        for(int x = 0 ; x < maps[0].length() ; x++){
            if(maps[y][x] != 'X' && !v[y][x]){
                int value = 0;
                v[y][x] = true;
                queue<pair<int, int>> q;
                q.push(make_pair(x, y));
                while(!q.empty()){
                    int now_x = q.front().first;
                    int now_y = q.front().second;
                    q.pop();
                    value += (maps[now_y][now_x] - '0');
                    for(int k = 0 ; k < nx.size() ; k++){
                        int next_x = now_x + nx[k];
                        int next_y = now_y + ny[k];
                        if(next_x > -1 && next_x < maps[0].length() && next_y > -1 && next_y < maps.size() && !v[next_y][next_x] && maps[next_y][next_x] != 'X'){
                            v[next_y][next_x] = true;
                            q.push(make_pair(next_x, next_y));
                        }
                    }
                }
                answer.push_back(value);
            }
        }
    }
    if(answer.empty()) return {-1};
    stable_sort(answer.begin(), answer.end());
    
    return answer;
}
