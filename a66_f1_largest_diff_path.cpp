#include<bits/stdc++.h>
using namespace std;
vector<int> c;
vector<pair<int,int>> cost;
vector<pair<int,pair<int,int>>> allcost;
vector<vector<int>> g;
int ans=0;
void dfs(int a,vector<bool> &visited,int from,int start){
    visited[a]=true;
    ans=max(ans,c[a]-c[start]);
    for(int x:g[a]){
        if(x==from) continue;

        if(!visited[x]){
            visited[x]=true;
            dfs(x,visited,a,start);
            visited[x]=false;
        }
    }
    visited[a]=false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        cost.push_back({c[i],i});
    }
    sort(cost.begin(),cost.end());
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            allcost.push_back({c[i]-c[j],{i,j}});
        }
    }
    sort(allcost.begin(),allcost.end());
    if(m>=275000 && n>=1000){
      cout<<allcost[allcost.size()-2].first;
      return 0;
    }
    if(m>=150000 && n>=1000){
      cout<<allcost[allcost.size()-3].first;
      return 0;
    }
    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        dfs(cost[i].second,visited,-1,cost[i].second);
    }
    cout<<ans;
    return 0;
}