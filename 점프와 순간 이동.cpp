// https://school.programmers.co.kr/learn/courses/30/lessons/12980

#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n > 1){
        if(n % 2 == 0) n /= 2;
        else{++ans; n /= 2;}
    }
    ++ans;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return ans;
}
