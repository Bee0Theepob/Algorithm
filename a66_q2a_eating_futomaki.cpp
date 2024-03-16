#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int  eat(int l,int r,vector<vector<int>> &have,vector<vector<int>> &ans){
    if(have[l][r]){
        return ans[l][r];
    }
    if(l+1==r){
        have[l][r]=true;
        return ans[l][r]=max(v[l],v[r]);
    }
    have[l][r]=true;
    return ans[l][r]=max({max(v[l],v[r]) + eat(l+1,r-1,have,ans),max(v[l],v[l+1]) + eat(l+2,r,have,ans),max(v[r],v[r-1]) + eat(l,r-2,have,ans)});
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    v.resize(n);
    vector<vector<int>> have(n,vector<int>(n));
    vector<vector<int>> ans(n,vector<int>(n));
    for(int &x:v){
        cin>>x;
    }
    cout<<eat(0,n-1,have,ans);
}