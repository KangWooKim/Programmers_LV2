//https://programmers.co.kr/learn/courses/30/lessons/1844

 #include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(0, 0)); int move = 1;
    visited[0][0] = 1;
    while(!bfs.empty()){
        int x = bfs.front().first;
        int y = bfs.front().second;
        bfs.pop();
        move = visited[x][y];
        if(x == maps.size() -1 && y == maps[0].size() - 1) return move;
        if(x != 0 && visited[x - 1][y] == 0 && maps[x - 1][y] == 1){
            bfs.push(make_pair(x - 1, y));
            visited[x - 1][y] = move + 1;
        }
        if(x != maps.size() - 1 && visited[x + 1][y] == 0 && maps[x + 1][y] == 1){
            bfs.push(make_pair(x + 1, y));
            visited[x + 1][y] = move + 1;
        }
        if(y != 0 && visited[x][y - 1] == 0 && maps[x][y - 1] == 1){
            bfs.push(make_pair(x, y - 1));
            visited[x][y - 1] = move + 1;
        }
        if(y != maps[0].size() - 1 && visited[x][y + 1] == 0 && maps[x][y + 1] == 1){
            bfs.push(make_pair(x, y + 1));
            visited[x][y + 1] = move + 1;
        }
    }
    return -1;
}
