//https://school.programmers.co.kr/learn/courses/30/lessons/169199

#include <bits/stdc++.h>

using namespace std;

vector<int> nx = {-1, 1, 0, 0};
vector<int> ny = {0, 0, -1, 1};
int size_x, size_y;

bool Isinside(int x, int y){
    return x > -1 && y > -1 && x < size_x && y < size_y;
}

int solution(vector<string> board) {
    int answer = 1234567;
    
    int start_x, start_y, goal_x, goal_y;
    size_x = board.size(); size_y = board[0].length();
    for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ; j < board[i].length() ; j++){
            if(board[i][j] == 'G'){goal_x = i; goal_y = j;}
            if(board[i][j] == 'R'){start_x = i; start_y = j;}
        }
    }
    queue<vector<int>> q;
    q.push({start_x, start_y, 0});
    set<vector<int>> st;
    st.insert({start_x, start_y});
    while(!q.empty()){
        int x = q.front()[0]; int y = q.front()[1]; int dis = q.front()[2];
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int next_x = x; int next_y = y;
            while(Isinside(next_x + nx[i], next_y + ny[i]) && board[next_x + nx[i]][next_y + ny[i]] != 'D'){
                next_x += nx[i]; next_y += ny[i];
            }
            if(st.count({next_x, next_y}) == 0){
                st.insert({next_x, next_y});
                q.push({next_x, next_y, dis + 1});
            }
            if(next_x == goal_x && next_y == goal_y){
                answer = min(answer, dis + 1);
            }
        }
    }
    if(st.count({goal_x, goal_y}) == 0) return -1;
    
    return answer;
}
