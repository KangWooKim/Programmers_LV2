// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    reverse(truck_weights.begin(), truck_weights.end());
    queue<pair<int, int>> q;
    int w = 0; int t = 0;
    while(!truck_weights.empty() || !q.empty()){
    
        while(!q.empty() && q.front().second == t){
            w -= q.front().first; q.pop();
        }
        if(!truck_weights.empty() && w + truck_weights.back() <= weight){
            w += truck_weights.back();
            q.push(make_pair(truck_weights.back(), t + bridge_length));
            truck_weights.pop_back();
        }
        ++t;
        
        
    }
    return t;
}
