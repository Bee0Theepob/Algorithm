#include<bits/stdc++.h>
using namespace std;
int  main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    priority_queue<pair<long long,pair<int,int>>> pq;
    map<int,vector<int>> group;
    map<int,int> headof;
    for(int i=0;i<n;i++){
        cin>>v[i];
        group[i].push_back(i);
        headof[i]=i;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            long long cost=v[i]^v[j];
            pq.push({cost,{i,j}});
        }
    }
        
    long long ans=0;
    int get=0;
    while(!pq.empty()){
        if(get==n-1){
            break;
        }

        pair<long long,pair<int,int>> u = pq.top();
        pq.pop();
        int a=u.second.first,b=u.second.second;
        if(headof[a]==headof[b]){
            continue;
        }

        int tmp=headof[b];
        for(int i=0;i<group[tmp].size();i++){
            group[headof[a]].push_back(group[tmp][i]);
            headof[group[tmp][i]]=headof[a];
        }
        group.erase(tmp);
        ans+=u.first;
        get++;
        
    }
    cout<<ans;
}