// https://school.programmers.co.kr/learn/courses/30/lessons/12953

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    while(arr.size() != 1){
        int a = arr.back();
        arr.pop_back();
        int b = arr.back();
        arr.pop_back();
        int gcd = 1;
        for(int i = b ; i > 0 ; i--){
            if(a % i == 0 && b % i == 0){
                gcd = i;
                break;
            }
        }
        arr.push_back(a * b / gcd);
    }
    return arr[0];
}
