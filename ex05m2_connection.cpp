#include<bits/stdc++.h>
using namespace std;
vector<int> deg;
int letsgo(int a,int k,int from,vector<bool> &visited,vector<vector<int>> &v){
    int result=0;
    queue<pair<int,int>> q;
    visited[a]=true;
    q.push(make_pair(a,0));
    while(!q.empty()){
        pair<int,int>  u=q.front();
        q.pop();
        if(u.second==k+1){
            return result;
        }
        result++;
        for(int x:v[u.first]){
            if(!visited[x]){
                visited[x]=true;
                q.push(make_pair(x,u.second+1));
            }
        }
    }
    return result;
}

int main(){
    int n,e,k;
    cin>>n>>e>>k;
    deg.resize(n);
    vector<vector<int>> v(n,vector<int>());
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        vector<bool> visited(n);
        deg[i]=letsgo(i,k,-1,visited,v);
    }
    // for(int i=0;i<n;i++){
    //     cout<<deg[i]<<' ';
    // }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,deg[i]);
    }
    cout<<ans;

    
    
    return 0;
}