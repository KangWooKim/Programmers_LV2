// https://programmers.co.kr/learn/courses/30/lessons/12899#

#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    int number = n;
    while(number != 0){
        int a = number % 3;
        if(a != 0) {
            answer += to_string(a); 
            number /= 3;
        }
        else {
            answer += "4"; 
            number /= 3; 
            
            number = number - 1;
        }
        
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
