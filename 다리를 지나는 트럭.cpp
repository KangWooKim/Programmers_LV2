// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> truck;
    queue<int> checkTime;
    int finish = 0; int w = 0; int time = 1; int idx = 0;
    while(finish < truck_weights.size()){
        time++;
        if(!checkTime.empty() && checkTime.front() == time){
            int x = truck.front(); truck.pop();
            w = w - x;
            checkTime.pop();
            finish = finish + 1;
        }
        if(idx < truck_weights.size() && w + truck_weights[idx] <= weight){
            w = w + truck_weights[idx];
            truck.push(truck_weights[idx]);
            checkTime.push(time + bridge_length);
            idx++;
        }
    }
    return time - 1;
}
