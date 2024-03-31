#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> edge;
map<pair<int,int>,int> weight;
int n,m,s;
vector<int> bellman(int s,vector<vector<int>> &dist){
    for(int i=0;i<n;i++){
        dist[0][i]=1e9;
    }
    dist[0][s]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=dist[i-1][j];
        }
        for(pair<int,int> p:edge){
            int a=p.first,b=p.second;
            if(dist[i][b] > dist[i-1][a] + weight[{a,b}]){
                dist[i][b] = dist[i-1][a] + weight[{a,b}];
            }
        }
    
    }
    for(pair<int,int> p:edge){
        int a=p.first,b=p.second;
        if(dist[n-1][b] > dist[n-1][a] + weight[{a,b}]){
            return {-1};
        }
    }
    return dist[n-1];
}

int main(){
    cin>>n>>m>>s;
    edge.resize(n);
    vector<vector<int>> dist(n,vector<int>(n));
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        edge.push_back({a,b});
        weight[{a,b}]=w;
    }
    vector<int> ans = bellman(s,dist);
    for(int x:ans){
        cout<<x<<' ';
    }

    return 0;
}