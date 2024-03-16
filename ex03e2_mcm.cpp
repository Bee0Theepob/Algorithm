#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp; 
vector<int> v;
int mcm(int l ,int r){
    if(mp.find({l,r})!=mp.end()){
        return mp[{l,r}];
    }
    if(l<r){
        int mincost=INT_MAX;
        for(int i=l;i<r;i++){
            int tmp = mcm(l,i)+mcm(i+1,r)+(v[l]*v[i+1]*v[r+1]);
            mincost=min(mincost,tmp);
        }
        return mp[{l,r}]=mincost;
    }
    else{
        return mp[{l,r}]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    v.resize(n+1);
    for(int i=0;i<n+1;i++){
        cin>>v[i];
    }
cout<<mcm(0,n-1);
}
