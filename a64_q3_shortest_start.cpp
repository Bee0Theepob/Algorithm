#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
map<pair<int,int>,int> weight;
priority_queue<pair<int,int>> pq;
void dijk(vector<int> &dist){
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
    vector<int> dist(n,1e9);
    g.resize(n);
    vector<int> start(k);
    for(int i=0;i<k;i++){
        cin>>start[i];
        dist[start[i]]=0;
        pq.push({0,start[i]});
    }
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back(b);
        weight[{a,b}]=w;
    }
    
    dijk(dist);
    int ans= dist[target];
    cout<<ans;
}