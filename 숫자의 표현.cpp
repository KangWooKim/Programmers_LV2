#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1 ; i <= n ; i++){
        int sum = 0;
        int start = i - 1;
        while(sum < n){
            ++start;
            sum += start;
            if(sum == n){
                answer++; break;
            }
        }
    }
    return answer;
}
