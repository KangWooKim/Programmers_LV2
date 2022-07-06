// https://school.programmers.co.kr/learn/courses/30/lessons/12914

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> v(2000, 0);
    v[0] = 0; v[1] = 1; v[2] = 2;
    for(int i = 3 ; i < n + 1 ; i++){
        v[i] = (v[i - 1] + v[i - 2]) % 1234567;
    }
    return v[n];
}
