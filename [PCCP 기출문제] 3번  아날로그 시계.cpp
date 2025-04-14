#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 문제에서 요구하는 solution 함수
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    // 시작 시각과 종료 시각을 초 단위로 변환
    double start = h1 * 3600 + m1 * 60 + s1;
    double end = h2 * 3600 + m2 * 60 + s2;
    
    // 시계의 각 손은 일정한 속도로 회전합니다.
    // 초침: 360초에 한 바퀴 => 6도/초
    // 분침: 3600초에 한 바퀴 => 0.1도/초
    // 시침: 43200초에 한 바퀴 => 1/120도/초
    //
    // 초침과 분침이 만나는 조건:
    //   6t - 0.1t = 5.9t가 360도의 배수
    //   => t = (360 * k) / 5.9,  k ∈ ℕ
    // 초침과 시침이 만나는 조건:
    //   6t - (t/120) = (719/120)t가 360도의 배수
    //   => t = (360 * k') / (719/120) = (43200 * k')/719,  k' ∈ ℕ
    //
    // 단, 세 바늘이 모두 겹치는 경우(즉, t가 0, 43200, …인 경우)는 중복으로
    // 카운트되지 않도록 해야 합니다.
    
    // 두 경우의 주기 (실수 계산)
    double period1 = 360.0 / (6.0 - 0.1);     // 초침, 분침 만남: 360/5.9
    double period2 = 43200.0 / 719.0;           // 초침, 시침 만남: 43200/719
    
    vector<double> events;
    const double eps = 1e-9; // 부동소수점 비교를 위한 오차
    
    // [1] 초침과 분침이 만나는 시점을 구합니다.
    // k는 0부터 시작하며, t = k * period1가 end 이하일 때까지 검사합니다.
    int maxK = (int)(end / period1) + 2;  // 안전하게 최대값 계산
    for (int k = 0; k <= maxK; k++) {
        double t = period1 * k;
        if(t < start - eps) continue;
        if(t > end + eps) break;
        events.push_back(t);
    }
    
    // [2] 초침과 시침이 만나는 시점을 구합니다.
    int maxL = (int)(end / period2) + 2;
    for (int l = 0; l <= maxL; l++) {
        double t = period2 * l;
        if(t < start - eps) continue;
        if(t > end + eps) break;
        events.push_back(t);
    }
    
    // [3] 두 경우에서 같은 시각 (거의 같은 실수값)인 경우를 하나로 합칩니다.
    sort(events.begin(), events.end());
    int count = 0;
    double last = -1e9;
    for (double t : events) {
        if(t - last > eps) {  // 이전 이벤트와 차이가 충분히 크면 중복이 아님
            count++;
            last = t;
        }
    }
    return count;
}
