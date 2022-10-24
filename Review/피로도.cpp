// https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <bits/stdc++.h>


using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(), dungeons.end());
    do{
        int adventure = 0; int T = k;
        for(int i = 0 ; i < dungeons.size() ; i++){
            if(T < dungeons[i][0]) break;
            else{
                T = T - dungeons[i][1];
                adventure++;
            }
        }
        if(answer < adventure) answer = adventure;
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}
