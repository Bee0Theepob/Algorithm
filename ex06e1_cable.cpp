#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,cost;
    cin>>n;
    map<int,vector<int>> group;
    map<int,int> headof;
    vector<pair<int,pair<int,int>>> costs;
    for(int i=0;i<n;i++){
        group[i].push_back(i);
        headof[i]=i;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cin>>cost;
            costs.push_back({cost,{i,j}});
        }
    }
    sort(costs.begin(),costs.end());
    int ans=0,get=0;
    for(int i=0;i<costs.size();i++){
        if(get==n-1){
            break;
        }

        cost=costs[i].first;
        int a=(costs[i].second).first,b=(costs[i].second).second;

        if(headof[a]==headof[b]){
            continue;
        }
        int r=group[headof[b]].size();
        for(int i=0;i<r;i++){
            group[headof[a]].push_back(group[headof[b]][i]);
        }
        int tmp=headof[b];
        for(int i=0;i<r;i++){
            headof[group[tmp][i]]=headof[a];
        }
        group.erase(tmp);
        ans+=cost;
        get++;
    }
    cout<<ans;
}