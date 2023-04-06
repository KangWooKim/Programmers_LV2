// https://school.programmers.co.kr/learn/courses/30/lessons/178870

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int start = 0; int end = 0; int sum = sequence[0];
    if(sum == k) answer = {start, end};
    while(end < sequence.size() && start <= end){
        if(sum < k){
            sum += sequence[++end];
        }
        else{
            sum -= sequence[start++];
        }
        
        if(sum == k){
            if(answer.size() == 0){
                answer = {start, end};
            }
            else if(answer[1] - answer[0] > end - start){
                answer = {start, end};
            }
        }
    }
    
    return answer;
}
