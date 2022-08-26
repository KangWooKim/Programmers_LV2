// https://school.programmers.co.kr/learn/courses/30/lessons/12978

#include <bits/stdc++.h>
using namespace std;

int route[51];
vector<pair<int, int>> graph[51];

void di(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    route[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(route[now] < dist) continue;
        for(int i = 0 ; i < graph[now].size() ; i++){
            int cost = dist + graph[now][i].second;
            if(cost < route[graph[now][i].first]){
                route[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(route, route + 51 , 987654321);
    for(auto r : road){
        graph[r[0]].push_back(make_pair(r[1], r[2]));
        graph[r[1]].push_back(make_pair(r[0], r[2]));
    }
    di(1);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    for(int i = 1 ; i <= N ; i++){
        if(route[i] <= K) answer++;
    }
    return answer;
}
