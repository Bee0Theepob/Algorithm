#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> visited; 

void get_all_node(int a,int from){
    visited[a]=true;
    for(int x:g[a]){
        if(x==from){
            continue;
        }

        if(!visited[x]){
            visited[x]=true;
            get_all_node(x,a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    visited.resize(n+1);
    for(int i=0;i<=n;i++){
        vector<int> tmp;
        g.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            get_all_node(i,-1);
            ans++;
        }
    }
    cout<<ans;
}
