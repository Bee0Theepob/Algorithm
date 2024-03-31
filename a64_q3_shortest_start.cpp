#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
map<pair<int,int>,int> weight;
void dijk(int a,vector<int> &dist){
    priority_queue<pair<int,int>> pq;
    pq.push({0,a});
    dist[a]=0;
    while(!pq.empty()){
        pair<int,int> u=pq.top();
        pq.pop();
        for(int x:g[u.second]){
            if(dist[x] > dist[u.second] + weight[{u.second,x}]){
                dist[x] = dist[u.second] + weight[{u.second,x}];
                pq.push({-dist[x],x});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k,target;
    cin>>n>>m>>k>>target;
    g.resize(n);
    vector<int> start(k);
    for(int i=0;i<k;i++){
        cin>>start[i];
    }
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        g[b].push_back(a);
        weight[{b,a}]=w;
    }
    vector<int> dist(n,1e9);
    dijk(target,dist);
    int ans=1e9;
    for(int i=0;i<k;i++){
        ans=min(ans,dist[start[i]]);
    }
    cout<<ans;
}