// https://school.programmers.co.kr/learn/courses/30/lessons/87377

#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<long long> x; vector<long long> y; vector<vector<long long>> xy;
    for(int i = 0 ; i < line.size() ; i++){
        for(int j = i + 1 ; j < line.size() ; j++){
            long long a = ((long long)line[i][0] * (long long)line[j][1]) - ((long long)line[i][1] * (long long)line[j][0]);
            long long b = ((long long)line[i][1] * (long long)line[j][2]) - ((long long)line[i][2] * (long long)line[j][1]);
            long long c = ((long long)line[i][2] * (long long)line[j][0]) - ((long long)line[i][0] * (long long)line[j][2]);
            if(a == 0 || b % a != 0 || c % a != 0) continue;
            x.push_back(b / a); y.push_back (c / a); xy.push_back({b / a , c / a});
        }
    }
    long long a1 = *max_element(x.begin(), x.end()); long long a2 = *min_element(x.begin(), x.end());
    long long b1 = *max_element(y.begin(), y.end()); long long b2 = *min_element(y.begin(), y.end());
    for(long long i = b1 ; i >= b2 ; i--){
        string s1 = "";
        for(long long j = a2 ; j <= a1 ; j++){
            vector<long long> v1 = {j, i};
            if(find(xy.begin(), xy.end(), v1) != xy.end()) s1.push_back('*');
            else s1.push_back('.');
        }
        answer.push_back(s1);
    }
    return answer;
}
