// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    vector<int> v;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '(') v.push_back(1);
        else if(s[i] == ')'){
            if(v.empty()) return false;
            v.pop_back();
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    if(!v.empty()) return false;
    return true;
}
