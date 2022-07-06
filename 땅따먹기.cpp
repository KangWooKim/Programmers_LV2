// https://school.programmers.co.kr/learn/courses/30/lessons/12913

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    for(int i = 1 ; i < land.size() ; i++){
        land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
        land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
        land[i][3] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][0]));
    }
    answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());

    return answer;
}
