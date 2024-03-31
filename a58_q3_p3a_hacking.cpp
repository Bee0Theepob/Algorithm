#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> weight;
int n,m,k;
vector<int> dijk(vector<int> v,vector<int> &dist){
    priority_queue<pair<int,int>> pq;
    pq.push({0,n});
    dist[n]=0;
    while(!pq.empty()){
        pair<int,int> u=pq.top();
        pq.pop();
        if(dist[u.second]<-u.first){
            break;
        }
        for(int x:g[u.second]){
            if(dist[x] > dist[u.second] + weight[x]){
                dist[x] = dist[u.second] + weight[x];
                pq.push({-dist[x],x});   
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>m>>k;
    g.resize(n+k);
    vector<int> virus(k);
    for(int i=0;i<k;i++){
        cin>>virus[i];
        g[n].push_back(virus[i]);
    }
    weight.resize(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n+k,1e9);
    vector<int> t=dijk(virus,dist);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dist[i]);
    }
    cout<<ans;

}
