// https://school.programmers.co.kr/learn/courses/30/lessons/49994

#include <bits/stdc++.h>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<vector<int>> route;
    vector<char> dir = {'U', 'D', 'R', 'L'};
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int x = 0; int y = 0;
    for(auto c : dirs){
        int idx = find(dir.begin(), dir.end(), c) - dir.begin();
        int nx = x + dx[idx]; int ny = y + dy[idx];
        if(nx > 5 || nx < -5 || ny > 5 || ny < -5) continue;
        vector<int> v = {x, y, nx, ny}; vector<int> v1 = {nx, ny, x, y};
        if(find(route.begin(), route.end(), v) == route.end() && find(route.begin(), route.end(), v1) == route.end()){
            answer++;
            route.push_back(v);
        }
        x = nx; y = ny;
    }
    return answer;
}
