//https://school.programmers.co.kr/learn/courses/30/lessons/70129

#include <string>
#include <vector>

using namespace std;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;  int res = 0;
    while(s != "1"){
        cnt++;
        int zero = 0;
        for(int i = 0 ; i < s.length() ; i++){
            string s1 = s.substr(i , 1);
            if(s1 == "0"){
                zero++;
            }
        }
        int val = s.length() - zero;
        res += zero;
        s = toBinary(val);
    }
    
    answer.push_back(cnt); answer.push_back(res);
    return answer;
}
