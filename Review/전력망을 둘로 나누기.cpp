// https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <bits/stdc++.h>

using namespace std;

int bfs(int number, vector<vector<int>> v){
    int k = 0;
    queue<int> q; q.push(number);
    int visit[101];
    for(int i = 0 ; i < 101 ; i++){visit[i] = 0;}
    visit[number] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0 ; i < v.size() ; i++){
            if(now == v[i][0] && visit[v[i][1]] != 1){q.push(v[i][1]); visit[v[i][1]] = 1;}
            if(now == v[i][1] && visit[v[i][0]] != 1){q.push(v[i][0]); visit[v[i][0]] = 1;}
        }
    }
    for(int i = 0 ; i < 101 ; i++){
        if(visit[i] == 1) k++;
    }
    return k;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    
    for(int i = 0 ; i < wires.size() ; i++){
        vector<vector<int>> v = wires;
        v.erase(v.begin() + i);
        int a = v[0][0];
        int k = bfs(a, v);
        answer = min(answer, abs(n - 2 * k));
    }
    
    return answer;
}
