// https://school.programmers.co.kr/learn/courses/30/lessons/77885

#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0 ; i < numbers.size() ; i++){
        if(numbers[i] % 2 == 0) answer.push_back(numbers[i] + 1);
        else{
            answer.push_back(numbers[i] + (((numbers[i] + 1) ^ numbers[i]) + 1) / 4);
        }
    }
    
    return answer;
}
