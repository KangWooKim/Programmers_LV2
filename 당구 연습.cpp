// https://school.programmers.co.kr/learn/courses/30/lessons/169198

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (auto& b : balls) {
        vector<int> distance;
        vector<int> Xlist(2, 0);
        vector<int> Ylist(2, 0);
        Xlist[0] = -b[0];
        Xlist[1] = m + m - b[0];
        Ylist[0] = -b[1];
        Ylist[1] = n + n - b[1];
        
        if (startY != b[1] && startX != b[0]) {
            for (int i = 0 ; i < 2 ; i++) {
                int d = ((startX - b[0]) * (startX - b[0])) + ((startY - Ylist[i]) * (startY - Ylist[i]));
                distance.push_back(d);
                d = ((startX - Xlist[i]) * (startX - Xlist[i])) + ((startY - b[1]) * (startY - b[1]));
                distance.push_back(d);
            }
        }
        else if (startY == b[1] && startX != b[0]) {
            for (auto& y : Ylist) {
                int d = ((startX - b[0]) * (startX - b[0])) + ((startY - y) * (startY - y));
                distance.push_back(d);
            }
            
            if (startX < b[0]) {
                int d = startX + b[0];
                distance.push_back(d * d);
            }
            else {
                int d = (m - startX) + (m - b[0]);
                distance.push_back(d * d);
            }
        }
        else if (startY != b[1] && startX == b[0]) {
            for (auto& x : Xlist) {
                int d = ((startX - x) * (startX - x)) + ((startY - b[1]) * (startY - b[1]));
                distance.push_back(d);
            }
            
            if (startY < b[1]) {
                int d = startY + b[1];
                distance.push_back(d * d);
            }
            else {
                int d = (n - startY) + (n - b[1]);
                distance.push_back(d * d);
            }
        }
        
        answer.push_back(*min_element(distance.begin(), distance.end()));
    }
    
    return answer;
}
