#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,pair<int,int>>> edges;
    vector<int> headof(n);
    map<int,vector<int>> groups;
    for(int i=0;i<n;i++){
        headof[i]=i;
        groups[i].push_back(i);
    }
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges.push_back({w,{a,b}});
    }
    sort(edges.begin(),edges.end());
    int now = n-1,i=0;
    vector<int> ans(n+1);
    ans[n]=0;
    while(i<m){
        w=edges[i].first;
        a=edges[i].second.first,b=edges[i].second.second;
        i++;
        if(headof[a]==headof[b]) continue;

        int tmp=headof[b];
        for(int j=0;j<groups[tmp].size();j++){
            groups[headof[a]].push_back(groups[tmp][j]);
            headof[groups[tmp][j]]=headof[a];
        }
        groups.erase(tmp);
        ans[now]=w;
        now--;
        if(now < 0) break;
    }
    while(q--){
        cin>>a;
        cout<<ans[a]<<'\n';
    }

    return 0;
}