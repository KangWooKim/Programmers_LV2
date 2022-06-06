// https://programmers.co.kr/learn/courses/30/lessons/12985

#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while(true){
        if((a > b && a % 2 == 0 && a == b + 1) || ( b > a && b % 2 == 0 && b == a + 1)) return answer;
        if(a % 2 == 0) a /= 2;
        else a = (a + 1) / 2;
        
        if(b % 2 == 0) b /= 2;
        else b = (b + 1) / 2;
        
        answer++;
        
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
