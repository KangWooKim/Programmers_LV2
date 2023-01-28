// https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    
    if(x == y) return answer;
    
    vector<int> v(y + 1, 99999);
    v[x] = 0;
    for(int index = x + 1 ; index <= y ; index++){
        int a = index / 2;
        int b = index / 3;
        int c = index - n;
        if(index % 2 == 0 && a >= x && v[a] != 99999 && v[index] > v[a] + 1){
            v[index] = v[a] + 1;
        }
        if(index % 3 == 0 && b >= x && v[b] != 99999 && v[index] > v[b] + 1){
            v[index] = v[b] + 1;
        }
        if(c >= x && v[c] != 99999 && v[index] > v[c] + 1){
            v[index] = v[c] + 1;
        }
    }
    answer = v[y];
    if(answer == 99999) return -1;
    
    return answer;
}
