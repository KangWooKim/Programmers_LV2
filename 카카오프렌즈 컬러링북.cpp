// https://school.programmers.co.kr/learn/courses/30/lessons/1829

#include <bits/stdc++.h>

using namespace std;

bool visited[100][100];

int color(vector<vector<int>> picture, int p, int q){
    int col = picture[p][q]; int res = 1;
    vector<vector<int>> v; v.push_back({q, p}); visited[p][q] = true;
    vector<int> mx = {0, 0, 1, -1};
    vector<int> my = {1, -1, 0, 0};
    while(!v.empty()){
        int x = v.back()[0]; int y = v.back()[1]; v.pop_back();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + mx[i]; int ny = y + my[i];
            if(nx >= picture[0].size() || nx < 0 || ny < 0 || ny >= picture.size()) continue;
            if(visited[ny][nx] ==false && picture[ny][nx] == col){
                v.push_back({nx, ny}); visited[ny][nx] = true; res++;
            }
        }
    }
    return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i = 0 ; i < 100 ; i++)
        for(int j = 0 ; j < 100 ; j++)
            visited[i][j] = false;
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && picture[i][j] != 0){
                int val = color(picture, i, j);
                max_size_of_one_area = max(val, max_size_of_one_area);
                number_of_area++;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
