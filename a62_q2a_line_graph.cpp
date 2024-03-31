#include <bits/stdc++.h>
#include <map>
using namespace std;
map<int,vector<int>> g;
vector<bool> visited;
vector<bool> del;
int ans=0;
bool isLine(int a,int from){
    if(g[a].size()>2){
        return false;
    }
    visited[a]=true;
    for(int x:g[a]){
        if(x==from){
            continue;
        }

        if(!visited[x]){
            visited[x]=true;
            bool tmp=isLine(x,a);
            visited[x]=false;
            if(tmp==false){
                return false;
            }
        }
        else{
            return false;
        }
    }
    for(int i=0;i<visited.size();i++){
        if(visited[i]) del[i]=true;
    }
    visited[a]=false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int v,e;
    cin>>v>>e;
    visited.resize(v);
    del.resize(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);g[b].push_back(a);
    }
    for(int i=0;i<v;i++){
        if(del[i]) continue;
        if(isLine(i,-1)){
            ans++;
        }
    }
    cout<<ans;


}