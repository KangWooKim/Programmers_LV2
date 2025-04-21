#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int solution(vector<vector<int>> info, int n, int m) {
    int L = info.size();
    // dp[b] = A흔적 최소합, B흔적 합 = b
    vector<int> dp(m, INF), next_dp(m, INF);
    dp[0] = 0;
    for (int i = 0; i < L; ++i) {
        fill(next_dp.begin(), next_dp.end(), INF);
        int a = info[i][0];
        int b = info[i][1];
        for (int sumB = 0; sumB < m; ++sumB) {
            if (dp[sumB] == INF) continue;
            int sumA = dp[sumB];
            // 1) A가 훔치기
            if (sumA + a < n) {
                next_dp[sumB] = min(next_dp[sumB], sumA + a);
            }
            // 2) B가 훔치기
            if (sumB + b < m) {
                next_dp[sumB + b] = min(next_dp[sumB + b], sumA);
            }
        }
        dp.swap(next_dp);
    }
    // 결과 계산
    int ans = INF;
    for (int sumB = 0; sumB < m; ++sumB) {
        if (dp[sumB] < n) {
            ans = min(ans, dp[sumB]);
        }
    }
    return (ans == INF ? -1 : ans);
}