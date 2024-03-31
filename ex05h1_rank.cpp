#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int>> g;
void win(int a,int b,vector<bool> &visited,int from){
    if(a==b){
        return;
    }
    if(from==-1){
        g[a][b]++;
    }
    visited[b]=true;
    for(auto it=g[b].begin();it!=g[b].end();it++){
        if(it->first==from){
            continue;
        }
        if(!visited[it->first]){
            visited[it->first]=true;
            win(a,it->first,visited,a);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        g[i];
    }
    while(p--){
        int a,b;
        cin>>a>>b;
        vector<bool> visited(n);
        win(a,b,visited,-1);
    }
    for(int i=0;i<n;i++){
        vector<bool> visited(n);
        for(auto x:g[i]){
            int j=x.first;
            if(i!=j){
                win(i,j,visited,-1);
            }           
        }
    }
    
    
    
    
    for(auto it=g.begin();it!=g.end();it++){
        cout<<it->first<<": ";
        map<int,int> mp=it->second;
        for(auto it2=(it->second).begin();it2!=(it->second).end();it2++){
            cout<<it2->first<<":"<<it2->second<<",";
        }
        cout<<'\n';
    }
}