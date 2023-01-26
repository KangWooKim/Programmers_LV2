// https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    vector<int> tmp;
    tmp.push_back(numbers.back());
    for(int i = numbers.size() - 2 ; i > -1 ; i--){
        if(numbers[i] >= tmp[0]){
            tmp.clear();
            tmp.push_back(numbers[i]);
            continue;
        }
        if(numbers[i] >= tmp.back()){
            while(tmp.back() <= numbers[i]){
                tmp.pop_back();
            }
        }
        answer[i] = tmp.back();
        tmp.push_back(numbers[i]);
        
    }
    
    return answer;
}
