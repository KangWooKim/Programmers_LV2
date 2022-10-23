// https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    int w, h;
    for(int i = 2 ; i < (brown + yellow) ; i++){
        if((brown + yellow) % i != 0) continue;
        w = max(i, (brown + yellow) / i);
        h = min(i, (brown + yellow) / i);
        if((2 * w + 2 * (h - 2) == brown)) break;
    }
    answer[0] = w; answer[1] = h;
    return answer;
}
