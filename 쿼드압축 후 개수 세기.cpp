// https://school.programmers.co.kr/learn/courses/30/lessons/68936

#include <bits/stdc++.h>
using namespace std;

void Quad(vector<vector<int>>& arr, int &zero, int &one, int row, int col, int l){
    if(l == 1){
        arr[row][col] == 1 ? one++ : zero++;
        return;
    }
    int sum = 0;
    for(int i = row ; i < row + l ; i++)
        for(int j = col ; j < col + l ; j++)
            sum += arr[i][j];
    
    if(sum == 0) {zero++; return;}
    else if(sum == l * l) {one++; return;}
    
    else{
        Quad(arr, zero, one, row, col, l / 2);
        Quad(arr, zero, one, row + l / 2 , col, l / 2);
        Quad(arr, zero, one, row, col + l / 2 , l / 2);
        Quad(arr, zero, one, row + l / 2, col + l / 2 , l / 2);
    }
    
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    Quad(arr, answer[0], answer[1], 0, 0, arr.size());
    return answer;
}
