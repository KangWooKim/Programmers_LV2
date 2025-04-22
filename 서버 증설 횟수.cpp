#include <vector>
using namespace std;
int solution(const vector<int> players, int m, int k) {
    int n = players.size();               // 항상 24
    // expire[i] : 시간 i에 만료되어 active에서 빠져나갈 서버 대수
    vector<int> expire(n + k, 0);
    int active = 0;   // 현재 운영 중인 서버 수
    int answer = 0;   // 총 증설(설치) 횟수
    for (int i = 0; i < n; ++i) {
        // 만료 시간에 다다른 서버들은 더 이상 active하지 않으므로 제거
        active -= expire[i];
        // 이 시간대에 필요한 서버 수 (players[i]명을 m 명씩 나눠)
        int required = players[i] / m;
        if (active < required) {
            int add = required - active;   // 추가로 설치해야 할 서버 수
            answer += add;
            active += add;
            // 설치한 서버는 i+k 시간에 만료
            expire[i + k] += add;
        }
    }
    return answer;
}