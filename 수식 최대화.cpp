//https://school.programmers.co.kr/learn/courses/30/lessons/67257

#include <bits/stdc++.h>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    string s1 = "";
    vector<char> opList;
    vector<char> op;
    vector<long long> number;
    opList.push_back('+'); opList.push_back('-'); opList.push_back('*');
    sort(opList.begin(), opList.end());
    for(int i = 0 ; i < expression.length() ; i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            op.push_back(expression[i]);
            number.push_back(stoi(s1));
            s1 = "";
        }
        else
            s1 += expression[i];
    }
    number.push_back(stoi(s1));
    
    do{
        vector<long long> val = number;
        vector<char> op1 = op;
        for(int i = 0 ; i < opList.size() ; i++){
            for(int j = 0 ; j < op1.size() ; j++){
                if(op1[j] == opList[i]){
                    if(op1[j] == '+'){
                        val[j] = val[j] + val[j + 1];
                    }
                    if(op1[j] == '-'){
                        val[j] = val[j] - val[j + 1];
                    }
                    if(op1[j] == '*'){
                        val[j] = val[j] * val[j + 1];
                    }
                    val.erase(val.begin() + j + 1);
                    op1.erase(op1.begin() + j);
                    j--;
                }
            }
        }
        if(answer < abs(val[0])) answer = abs(val[0]);
        
    }while(next_permutation(opList.begin(), opList.end()));
    return answer;
}    
