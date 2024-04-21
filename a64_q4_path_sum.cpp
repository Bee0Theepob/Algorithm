#include<bits/stdc++.h>
using namespace std;
set<int> dist;
vector<vector<int>> g;
map<pair<int,int>,int> weights;
void dfs(int a,int sumdist,vector<bool> &visited,int from){
    visited[a]=true;
    for(int x:g[a]){
        if(x==from) continue;

        if(!visited[x]){
            visited[x]=true;
            dist.insert(sumdist+weights[{a,x}]);
            dfs(x,sumdist+weights[{a,x}],visited,a);
            visited[x]=false;
        }
    }
    visited[a]=false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,w;
    cin>>n>>m;
    g.resize(n);
    vector<int> v;
    int t=8;
    while(t--){
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g[a].push_back(b);
        g[b].push_back(a);
        weights[{a,b}]=w;
        weights[{b,a}]=w;
    }
    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        dfs(i,0,visited,-1);
    }
    for(int i=0;i<8;i++){
        if(dist.find(v[i])!=dist.end()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}