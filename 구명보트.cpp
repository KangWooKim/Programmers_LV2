// https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(), people.rend());
    int index = people.size() - 1;
    int leftPeople = people.size();
    for(int i = 0 ; i < people.size() ; i++){
        if(people[i] <= limit / 2){
            break;
        }
        if(people[i] + people[index] <= limit){
            index--;
            answer++;
            leftPeople -= 2;
        }
        else if(people[i] + people[index] > limit){
            answer++;
            leftPeople--;
        }
    }
    
    answer += (leftPeople + 1) / 2;
    return answer;
}
