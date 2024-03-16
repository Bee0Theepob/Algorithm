#include <bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>> mp;
map<int,int> countt;

bool valid(vector<pair<int,int>> v,int target){
  for(pair<int,int> p:v){
    if(target!=p.first && target!=p.second){
      return true;
    }
    else{
      if(target==p.first && target==p.second){
        if(countt[target]>2){
          return true;
        }
      }
      else if(target==p.first || target==p.second){
        if(countt[target]>1){
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,t;
    cin>>n>>m;
    vector<int> v;
    cin>>t;
    v.push_back(t);
    countt[t]++;
    for(int i=1;i<n;i++){
      cin>>t;
      countt[t]++;
      if(t!=v[v.size()-1]){
        v.push_back(t);
        for(int j=i-1;j>=0;j--){
          mp[v[i]+v[j]].push_back({v[i],v[j]});
        }
      }
    }
    while(m--){
      cin>>t;
      bool trig=true;
      for(int i=0;i<v.size();i++){
        int target=t-v[i];
        auto it=mp.find(target);
        if(it!=mp.end()){
          trig=false;
          if(valid(mp[target],v[i])){
            cout<<"YES";
            break;
          }
          else{
            cout<<"NO";
            break;
          }
        }
        else{
          continue;
        }
      } 
      if(trig){
        cout<<"NO";
      }
      cout<<'\n';
    }
}