#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    // 왼쪽 선수가 먹을 음식을 담을 문자열
    string s1 = "";
    // 오른쪽 선수가 먹을 음식을 담을 문자열 (역순)
    string s2 = "";
    
    // 1번 음식부터 순회 (0번은 물이므로 제외)
    for(int i = 1 ; i < food.size() ; i++){
        // 각 음식을 두 선수가 동일하게 나눠 먹을 수 있는 개수 계산
        int a = food[i] / 2;
        
        // 계산된 개수만큼 음식 배치
        for(int k = 0 ; k < a ; k++){
            // 왼쪽 선수는 순서대로 추가
            s1 = s1 + to_string(i);
            // 오른쪽 선수는 역순으로 추가 (앞에 붙임)
            s2 = to_string(i) + s2;
        }
    }
    
    // 최종 음식 배치: 왼쪽 선수 + 물(0) + 오른쪽 선수
    answer = s1 + "0" + s2;
    
    return answer;
}