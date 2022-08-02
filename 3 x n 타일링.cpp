//https://school.programmers.co.kr/learn/courses/30/lessons/12902

#include <bits/stdc++.h>

using namespace std;

long long value[5001];
const int mod_value = 1000000007;

long long sol(int number){
    long long& res = value[number];
    if(res != 0) return res;
    res += 3 * sol(number - 2);
    for(int k = 4 ; k <= number ; k+=2){
        res += 2 * sol(number - k);
    }
    res %= mod_value;
    return res;
}

int solution(int n) {
    int answer = 0;
    value[0] = 1; value [2] = 3;
    answer = sol(n);
    return answer;
}
