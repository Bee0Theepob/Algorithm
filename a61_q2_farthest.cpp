#include<bits/stdc++.h>
using namespace std;
vector<int> dist;
map<pair<int,int>,int> weight;
map<int,vector<int>> g;
int dijk(int a,int target,vector<int> &dist){
    priority_queue<pair<int,int>> pq;
    pq.push({0,a});
    dist[a]=0;
    while(!pq.empty()){
        pair<int,int> u=pq.top();
        pq.pop();
        if(u.second==target){
            return dist[u.second];
        }
        for(int x:g[u.second]){
            if(dist[x]>dist[u.second]+weight[{u.second,x}]){
                dist[x]=dist[u.second]+weight[{u.second,x}];
                pq.push({-dist[x],x});
            }
        }
    }
    return dist[target];
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> w(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
            if(w[i][j]>0){
                weight[{i,j}]=w[i][j];
                g[i].push_back(j);
            }
        }
    }
    int ans=-1;
    for(int i=2;i<=n;i++){
        vector<int> dist(n+1,1e9);
        int x=dijk(1,i,dist);
        if(x==-1){
            cout<<-1;
            return 0;
        }
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
    
}