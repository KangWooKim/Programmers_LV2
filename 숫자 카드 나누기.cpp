// https://school.programmers.co.kr/learn/courses/30/lessons/135807

#include <bits/stdc++.h>
using namespace std;

bool check1(vector<int>& v, int i){
    for(int a = 0 ; a < v.size() ; a++){
        if(v[a] % i != 0)
            return false;
    }
    return true;
}

bool check2(vector<int>& v, int i){
    for(int a = 0 ; a < v.size() ; a++){
        if(v[a] % i ==0)
            return false;
    }
    return true;
}

vector<int> divide(int a){
    vector<int> v;
    for(int i = 2 ; i <= a ; i++){
        if(a % i == 0){
            v.push_back(i);
        }
    }
    return v;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    stable_sort(arrayA.begin(), arrayA.end());
    stable_sort(arrayB.begin(), arrayB.end());
    vector<int> v1, v2;
    v1 = divide(arrayA[0]); v2 = divide(arrayB[0]);
    for(int i = v1.size() - 1 ; i > -1 ; i--){
        if(check1(arrayA, v1[i]) && check2(arrayB, v1[i])){
            answer = v1[i];break;
        }
    }
    for(int i = v2.size() - 1 ; i > -1 ; i--){
        if(v2[i] < answer) break;
        if(check2(arrayA, v2[i]) && check1(arrayB, v2[i])){
            answer = v2[i]; break;
        }
    }
    
    return answer;
}
