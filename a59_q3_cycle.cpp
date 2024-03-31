#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> g;
map<int,int> dis;
vector<bool> visited;
int loopPart;
bool find_loop(int a,int from){
    visited[a]=true;
    dis[a]=dis[from]+1;
    for(int x:g[a]){
        if(x==from){
                continue;
        }
        if(!visited[x]){
            visited[x]=true;
            dis[x]=dis[a]+1;
            if(find_loop(x,a)){
                return true;
            }
            visited[x]=false;
        }
        else{
            cout<<dis[a]-dis[x]+1;
            return true;
        }
    }
    visited[a]=false;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    dis[-1]=-1;
    visited.resize(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(find_loop(i,-1)){
            break;
        }
    }
}