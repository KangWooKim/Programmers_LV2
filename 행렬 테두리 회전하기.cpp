// https://school.programmers.co.kr/learn/courses/30/lessons/77485

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns, 0));
    int z = 1;
    for(int i = 0 ; i < rows ; i++)
        for(int j = 0 ; j < columns ; j++){
            v[i][j] = z++;
        }
    
    for(auto k : queries){
        int x1 = k[0]; int x2 = k[2]; int y1 = k[1]; int y2 = k[3];
        x1--; x2--; y1--; y2--; int xnow = x1; int ynow = y1; 
        vector<int> move;
        for(int y = y1 ; y < y2 ; y++){
            move.push_back(v[x1][y]);
        }
        for(int x = x1 ; x < x2 ; x++){
            move.push_back(v[x][y2]);
        }
        for(int y = y2 ; y > y1 ; --y){
            move.push_back(v[x2][y]);
        }
        for(int x = x2 ; x > x1 ; --x){
            move.push_back(v[x][y1]);
        }
        answer.push_back(*min_element(move.begin(), move.end()));
        rotate(move.begin(), move.end() - 1, move.end()); int idx = 0;
        for(int y = y1 ; y < y2 ; ++y){
            v[x1][y] = move[idx++];
        }
        for(int x = x1 ; x < x2 ; ++x){
            v[x][y2] = move[idx++];
        }
        for(int y = y2 ; y > y1 ; --y){
            v[x2][y] = move[idx++];
        }
        for(int x = x2 ; x > x1 ; --x){
            v[x][y1] = move[idx++];
        }
    }
    
    return answer;
}
