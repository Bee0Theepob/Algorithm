#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<pair<int,int>,int> mp;
int B(int l,int r){
    if(mp.find({l,r})!=mp.end()){
        return mp[{l,r}];
    }
    if(l+1==r){
        return mp[{l,r}]=max(0,v[l]*v[r]);
    }
    if(l==r){
        return 0;
    }
    else{
        int ans=0;
        for(int p=l;p<=r-1;p++){
            for(int q=p+1;q<=r;q++){
                ans=max(ans,B(l,p-1)+B(p+1,q-1)+B(q+1,r)+v[p]*v[q]);
            }
        }
        return mp[{l,r}]=ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
        cin>>a;
        if(a!=0){
            v.push_back(a);
        }
    }
    cout<<B(0,v.size()-1);
}