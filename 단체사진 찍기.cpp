// https://school.programmers.co.kr/learn/courses/30/lessons/1835

#include <bits/stdc++.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends1 = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do{
        bool a = true;
        for(int i = 0 ; i < n ; i++){
            char c1 = data[i][0]; char c2 = data[i][2]; char c3 = data[i][3];
            int dis = stoi(data[i].substr(4, 1));
            int k = abs(find(friends1.begin(), friends1.end(), c1) - find(friends1.begin(), friends1.end(), c2));
            k--;
            if(c3 == '='){
                if(k != dis){a = false; break;}
            }
            else if(c3 == '>'){
                if(k <= dis){a = false; break;}
            }
            else if(c3 == '<'){
                if(k >= dis){a = false; break;}
            }
        }
        if(a) answer++;
    }while(next_permutation(friends1.begin(), friends1.end()));
    return answer;
}
