// https://school.programmers.co.kr/learn/courses/30/lessons/12946

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> ans;

vector<vector<int>> tower(int n, int a, int b , int c){
    vector<vector<int>> res; vector<vector<int>> res1;
    if(n == 1){
        return {{a, c}};
    }
    res = tower(n - 1 , a, c, b);
    res.push_back({a, c});
    res1 = tower(n - 1, b, a, c);
    for(auto v : res1)
        res.push_back(v);
    return res;
    
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    return tower(n, 1, 2, 3);
}
