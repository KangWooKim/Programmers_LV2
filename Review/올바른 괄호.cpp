// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    int cnt = 0;
    for(auto& c : s){
        if(c == '(') cnt++;
        if(c == ')') cnt--;
        if(cnt < 0) return false;
    }
    if(cnt != 0) return false;
    return answer;
}
