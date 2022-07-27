// https://school.programmers.co.kr/learn/courses/30/lessons/87390

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left ; i <= right ; i++){
        int val = i / n;
        int res = i % n;
        val++; res++;
        if(val > res) answer.push_back(val);
        else answer.push_back(res);
    }
    return answer;
}
