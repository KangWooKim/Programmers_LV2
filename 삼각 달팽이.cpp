// https://school.programmers.co.kr/learn/courses/30/lessons/68645

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    for(int i = 1 ; i < n + 1 ; i++){
        vector<int> v0(i, 0);
        v.push_back(v0);
    }
    int move = n; int nowrow = -1; int nowcol = 0; int nownum = 0;
    while(move > 0){
        for(int i = 0 ; i < move ; i++){
            v[++nowrow][nowcol] = ++nownum;
        }
        for(int i = 0 ; i < move - 1 ; i++){
            v[nowrow][++nowcol] = ++nownum;
        }
        for(int i = 0 ; i < move - 2 ; i++){
            v[--nowrow][--nowcol] = ++nownum;
        }
        move -= 3;
    }
    
    for(int i = 0 ; i < v.size(); i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}
