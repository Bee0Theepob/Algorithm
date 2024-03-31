#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
void letsgo(int a,vector<int> &fare){
    queue<int> qq;
    // cout<<a<<' ';
    qq.push(a);
    fare[a]=0;
    while(!qq.empty()){
        int p=qq.front();
        qq.pop();
        for(int x:g[p]){
            if(fare[x]==-1){
                fare[x]=fare[p]+1;
                qq.push(x);
                // cout<<x<<' ';
            }
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    g.resize(n+1);
    vector<int> fareA(n+1,-1);
    vector<int> fareB(n+1,-1);
    vector<int> fareC(n+1,-1);
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        while(s--){
            int t;
            cin>>t;
            g[i].push_back(t);
            // g[t].push_back(i);
        }
    }
    letsgo(a,fareA);
    letsgo(b,fareB);
    letsgo(c,fareC);
    int ans=1e9;
    for(int i=1;i<=n;i++){
        if(fareA[i]<0 ||fareB[i]<0 ||fareC[i]<0){
            continue;

        }
        ans=min(ans,max({fareA[i],fareB[i],fareC[i]}));
    }
    cout<<ans;
}