// https://programmers.co.kr/learn/courses/30/lessons/92334

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k){
  
  const int a = id_list.size();
  map<string, int> matrix;
  for(int i = 0 ; i < a ;  i++) matrix[id_list[i]] = i;
  
  vector<pair<int, int>> v;
  sort(report.begin(), report.end());
  report.erase(unique(report.begin(), report.end()), report.end());
  
  for(const auto& k : report) {
    stringstream in(k);
    string a,b; in >> a >> b;
    v.push_back({matrix[a], matrix[b]});
  }
  
  vector<int> p(a), q(a);
  for(const auto& [a, b] : v) p[b]++;
  for(const auto& [a, b] : v) if(p[b] >= k) q[a]++;
  return q;
}
