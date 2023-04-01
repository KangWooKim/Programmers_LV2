// https://school.programmers.co.kr/learn/courses/30/lessons/176962

#include <bits/stdc++.h>

using namespace std;

int time_to_integer(string time){
    if(time.length() == 5)
        return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
    else
        return stoi(time);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    vector<tuple<string, int, int>> plan;
    vector<tuple<string, int, int>> pause;
    tuple<string, int, int> progress;
    int time_now;
    
    for(auto& p : plans){
        plan.push_back({p[0], time_to_integer(p[1]), time_to_integer(p[2])});
    }
    
    stable_sort(plan.begin(), plan.end(), [](const auto& a, const auto& b){
        return get<1>(a) < get<1>(b);
    });
    
    progress = plan[0];
    time_now = get<1>(progress);
    
    for(size_t i = 1 ; i < plan.size() ; i++){
        if(time_now + get<2>(progress) > get<1>(plan[i])){
            int time_left = get<1>(plan[i]) - time_now;
            pause.push_back({get<0>(progress), get<1>(progress), get<2>(progress) - time_left});
            progress = plan[i];
            time_now = get<1>(plan[i]);
            continue;
        }
        else if(time_now + get<2>(progress) <= get<1>(plan[i])){
            time_now += get<2>(progress);
            answer.push_back(get<0>(progress));
        }
        if(pause.empty() && time_now < get<1>(plan[i])){
            time_now = get<1>(plan[i]);
            progress = plan[i];
            continue;
        }
        if(!pause.empty() && time_now < get<1>(plan[i])){
            while(!pause.empty()){
                if(time_now + get<2>(pause.back()) <= get<1>(plan[i])){
                    answer.push_back(get<0>(pause.back()));
                    time_now += get<2>(pause.back());
                    pause.pop_back();
                }
                else if(time_now + get<2>(pause.back()) > get<1>(plan[i])){
                    int time_left = get<1>(plan[i]) - time_now;
                    tuple<string, int, int> res = {get<0>(pause.back()), get<1>(pause.back()), get<2>(pause.back()) - time_left};
                    pause.pop_back();
                    pause.push_back(res);
                    time_now = get<1>(plan[i]);
                    break;
                }
            }
        }
        progress = plan[i];
        time_now = get<1>(plan[i]);
    }
    answer.push_back(get<0>(plan.back()));
    
    if(!pause.empty()){
        while(!pause.empty()){
            answer.push_back(get<0>(pause.back()));
            pause.pop_back();
        }
    }
    
    return answer;
}

/*
1. 작업 시작
2. 
*/
