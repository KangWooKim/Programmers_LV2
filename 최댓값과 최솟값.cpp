#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream in(s);
    int max, min;
    in >> min;
    max = min;
    int pos;
    while(in >> pos){
        if(min > pos) min = pos;
        if(max < pos) max = pos;
    }
    
    answer = to_string(min) + " " + to_string(max);
    return answer;
}
