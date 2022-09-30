// https://school.programmers.co.kr/learn/courses/30/lessons/42577#

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    stable_sort(phone_book.begin(), phone_book.end());
    for(int i = 0 ; i < phone_book.size() - 1 ; i++){
        if(phone_book[i + 1].length() >= phone_book[i].length() && phone_book[i + 1].substr(0, phone_book[i].length()) == phone_book[i]){
            return false;
        }
    }
    return answer;
}
