// https://programmers.co.kr/learn/courses/30/lessons/12981

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> list;
    int index = 0;
    
    for(int i = 0 ; i < words.size() ; i++){
        string s = words[i];
        if(list.find(s) != list.end()){
            index = i;
            break;
        }
        if(i > 0 && words[i - 1].back() != s.front()){
            index = i;
            break;
        }
        list.insert(s);
    }
    if(index == 0){
        answer.push_back(index); answer.push_back(index);
    }
    else{
        answer.push_back((index % n) + 1); answer.push_back((index / n) + 1);
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return answer;
}
