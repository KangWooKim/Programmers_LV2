#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    vector<int> v1(A); vector<int> v2(B);
    sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
    for(int i = 0 ; i < v1.size() ; i++){
        answer = answer + v1[i] * v2[v2.size() - 1 - i];
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}

/*
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B){
    sort(A.begin(),A.end());  sort(B.rbegin(),B.rend());
    return inner_product(A.begin(),A.end(),B.begin(),0);
}
*/
