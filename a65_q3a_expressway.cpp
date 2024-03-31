#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;

int dijk(int a,int target,vector<int> &dist,vector<vector<int>> &c){
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
            if(dist[x] > dist[u.second] + c[u.second][x]){
                dist[x] = dist[u.second] + c[u.second][x];
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
    g.resize(n+1);
    vector<vector<int>> c(n+1,vector<int>(n+1));
    cin>>c[1][2];
    c[2][1]=c[1][2];
    g[1].push_back(2);
    g[2].push_back(1);
    for(int i=3;i<=n;i++){
        int b;
        cin>>b;
        while(b--){
            int t,p;
            cin>>t>>p;
            g[i].push_back(t);
            g[t].push_back(i);
            c[i][t]=p;
            c[t][i]=p; 
        }
    vector<int> dist(n,1e9);
    cout<<dijk(1,2,dist,c)<<' ';

    }
    return 0;
}