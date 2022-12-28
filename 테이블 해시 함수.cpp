// https://school.programmers.co.kr/learn/courses/30/lessons/147354

#include <bits/stdc++.h>

using namespace std;

int val;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[val - 1] == v2[val - 1]){
        return v1[0] > v2[0];
    }
    else
        return v1[val - 1] < v2[val - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    val = col;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    
    stable_sort(data.begin(), data.end(), cmp);
    vector<int> res;
    
    for(int i = row_begin - 1 ; i <= row_end - 1 ; i++){
        int sum = 0;
        for(int k = 0 ; k < data[i].size() ; k++){
            sum += (data[i][k] % (i + 1));
        }
        res.push_back(sum);
    }
    answer = res[res.size() - 1]; res.pop_back();
    for(auto& r : res){
        answer = answer ^ r;
    }
    return answer;
}
