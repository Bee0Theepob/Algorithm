#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,e,k;
    cin>>n>>e>>k;
    g.resize(n+1);
    vector<bool> visisted(n+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;
    queue<int> q;
    q.push(0);
    visisted[0]=true;
    k--;
    while(k--){
        int r=q.size();
        while(r--){
            int u=q.front();
            q.pop();
            for(int x:g[u]){
                if(!visisted[x]){
                    visisted[x]=true;
                    q.push(x);
                }
            }
        }
    }
    int r=q.size();
    while(r--){
        int u=q.front();
        q.pop();
        for(int x:g[u]){
            if(!visisted[x]){
                visisted[x]=true;
                q.push(x);
                ans++;
            }
        }
    }
    cout<<ans;
}