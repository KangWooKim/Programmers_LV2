// https://school.programmers.co.kr/learn/courses/30/lessons/159993

#include <bits/stdc++.h>
using namespace std;

vector<int> nx = {1, -1, 0, 0};
vector<int> ny = {0, 0, 1, -1};

int solution(vector<string> maps) {
    int answer = 0;
    
    vector<string> m = maps;
    vector<vector<int>> v1(maps.size(), vector<int>(maps[0].length(), 0));
    vector<vector<int>> v2(maps.size(), vector<int>(maps[0].length(), 0));
    queue<pair<int, int>> q;
    int sx; int sy; int ex; int ey; int lx; int ly;
    for(int i = 0 ; i < maps.size() ; i++)
        for(int j = 0 ; j < maps[0].length(); j++){
            if(maps[i][j] == 'S'){ sx = i; sy = j;}
            if(maps[i][j] == 'E'){ ex = i; ey = j;}
            if(maps[i][j] == 'L'){ lx = i; ly = j;}
        }
    v1[sx][sy] = 1;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < nx.size() ; i++){
            int mx = x + nx[i];
            int my = y + ny[i];
            if(mx < 0 || mx >= maps.size() || my < 0 || my >= maps[0].length()) continue;
            if(maps[mx][my] != 'X' && v1[mx][my] == 0){
                v1[mx][my] = v1[x][y] + 1;
                q.push(make_pair(mx, my));
            }
        }
    }
    
    if(v1[lx][ly] == 0) return -1;
    
    v2[lx][ly] = 1;
    q.push(make_pair(lx, ly));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < nx.size() ; i++){
            int mx = x + nx[i];
            int my = y + ny[i];
            if(mx < 0 || mx >= maps.size() || my < 0 || my >= maps[0].length()) continue;
            if(maps[mx][my] != 'X' && v2[mx][my] == 0){
                v2[mx][my] = v2[x][y] + 1;
                q.push(make_pair(mx, my));
            }
        }
    }
    if(v2[ex][ey] == 0) return -1;
    answer = v1[lx][ly] + v2[ex][ey] - 2;
    
    return answer;
}
