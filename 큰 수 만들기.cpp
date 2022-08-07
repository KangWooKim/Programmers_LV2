// https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {    
    for(int i = 0; i < number.size() && k > 0; i++) {
        if(number[i] < number[i + 1]) {
            number.erase(i, 1);
            if(i == 0) i--;
            else i -= 2;
            k--;
        }
    }

    if(k > 0)
        number.erase(number.size() - k, k);

    return number;
}
