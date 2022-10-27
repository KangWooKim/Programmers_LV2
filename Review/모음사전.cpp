// https://school.programmers.co.kr/learn/courses/30/lessons/84512

#include <bits/stdc++.h>

using namespace std;
int order[5][5] = {{   1,  782, 1563, 2344, 3125},
                   {   1,  157,  313,  469,  625},
                   {   1,   32,   63,   94,  125},
                   {   1,    7,   13,   19,   25},
                   {   1,    2,    3,    4,    5}};
int func(char c) {
    if (c == 'A') return 0;
    else if (c == 'E') return 1;
    else if (c == 'I') return 2;
    else if (c == 'O') return 3;
    else if (c == 'U') return 4;
}
int solution(string word) {
    int answer = 0;
    for (int i = 0; i < word.size(); i++) {
        answer += order[i][func(word[i])];
    }
    return answer;
}
