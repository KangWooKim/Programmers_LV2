// https://school.programmers.co.kr/learn/courses/30/lessons/17683#

#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string divid) {
	vector<string> v;
	int start = 0;
	int d = s.find(divid);
	while (d != -1){
		v.push_back(s.substr(start, d - start));
		start = d + 1;
		d = s.find(divid, start);
	} 
	v.push_back(s.substr(start, d - start));

	return v;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string search = "";
    for(int i = 0 ; i < m.length() ; i++){
        char c = m[i];
        if(i + 1 < m.length() && m[i + 1] == '#'){
            i++; c = tolower(c);
        }
        search += c;
    }
    vector<vector<string>> list(musicinfos.size(), vector<string>(2, ""));
    vector<int> time;
    for(int i = 0 ; i < musicinfos.size() ; i++){
        vector<string> v = split(musicinfos[i], ",");
        int len = abs((stoi(v[0].substr(0, 2)) - stoi(v[1].substr(0, 2))) * 60 + stoi(v[0].substr(3, 2)) - stoi(v[1].substr(3, 2)));
        list[i][0] = v[2];
        string melody = "";
        for(int i = 0 ; i < v[3].length() ; i++){
            char c = v[3][i];
            if(i + 1 < v[3].length() && v[3][i + 1] == '#'){
                i++; c = tolower(c);
            }
            melody += c;
        }
        string s0 = ""; int idx = 0;
        while(s0.length() != len){
            if(idx > melody.length() - 1) idx = 0;
            s0 += melody[idx];
            idx++;
        }
        list[i][1] = s0;
        time.push_back(len);
    }
    int mtime = -1;
    for(int i = 0 ; i < list.size() ; i++){
        if(list[i][1].find(search) != std :: string :: npos) {if(mtime < time[i]) {answer = list[i][0]; mtime = time[i];}}
    }
    if(answer == "") answer = "(None)";
    return answer;
}
