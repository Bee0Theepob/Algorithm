#include<bits/stdc++.h>
using namespace std;

bool solve(int a,map<int,vector<int>> &g,vector<bool> &visited,int from){
    visited[a]=true;
    for(int x:g[a]){
        if(x==from){
            continue;
        }
        if(!visited[x]){
            if(solve(x,g,visited,a)){
                return true;
            }
            visited[x]=false;
        }
        else{
            return true;
        }
    }
    visited[a]=false;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        map<int,vector<int>> g;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            g[i];
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if(n<=2 || m<3){
            cout<<"NO\n";
        }
        else{
            bool trig=true;
            vector<bool> visited(n);
            for(int i=0;i<n;i++){
                if(solve(i,g,visited,-1)){
                    cout<<"YES\n";
                    trig=false;
                    break;
                }
            }
            if(trig){
                cout<<"NO\n";
            }
            
        }
    }
}