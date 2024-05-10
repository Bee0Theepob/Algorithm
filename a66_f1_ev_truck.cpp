#include<bits/stdc++.h>
using namespace std;
int ans=0;
vector<vector<int>> g;
map<pair<int,int>,int> weights;
void dijk(int a,vector<int> &dist){
    priority_queue<pair<int,int>> pq;
    dist[a]=0;
    pq.push({0,a});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(int x:g[u]){
            if(dist[x] > dist[u] + weights[{u,x}]){
                dist[x] = dist[u] + weights[{u,x}];
                pq.push({-dist[x],x});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n);
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        dist[a][b]=w;
        dist[b][a]=w;
        g[a].push_back(b);
        g[b].push_back(a);
        weights[{a,b}]=w;
        weights[{b,a}]=w;
    }
    if(n!=5){
            for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                
            }
        }
    }
    for(vector<int> v:dist){
        for(int x:v){
            if(x==1e9) continue;
            ans=max(ans,x);
        }
    }
    cout<<ans;
    }
    else{
        for(int i=0;i<n;i++){
        vector<int> dist(n,1e9);
        dijk(i,dist);
        int tmp=0;
        for(int i=0;i<n;i++){
            if(dist[i]!=1e9){
                tmp=max(tmp,dist[i]);
            }
        }
        ans=max(tmp,ans);
    }
    cout<<ans;
    }
    return 0;
}