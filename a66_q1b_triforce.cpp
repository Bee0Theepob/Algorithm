#include<bits/stdc++.h>
using namespace std;

int tricheck(vector<vector<int>> &v,int t,int b,int l,int r){
    if(r-l<2 && b-t<2){
        map<int,int> mp;
        mp[v[t][l]]++;
        mp[v[t][r]]++;
        mp[v[b][l]]++;
        mp[v[b][r]]++;
        if(v[t][r]==0 || v[t][l]==0 || v[b][l]==0 || v[b][r]!=0){
            return 0;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>1){
                return it->first;
            }
        }
        return 0;
    }
    else{
    int m=(t+b)/2,m2=(l+r)/2;
    int p=tricheck(v,t,m,l,m2);
    int q=tricheck(v,t,m,m2+1,r);
    int r2=tricheck(v,m+1,b,l,m2);
    for(int i=m+1;i<=b;i++){
        for(int j=m2+1;j<=r;j++){
            if(v[i][j]!=0){
                return 0;
            }
        }
    }
    if(p==0 || q==0 || r2==0){
        return 0;
    }
    map<int,int> mp;
    mp[p]++;
    mp[q]++;
    mp[r2]++;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>=2){

            return it->first;
        }
    }   
    return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=3;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
        cout<<tricheck(v,0,n-1,0,n-1)<<'\n';
    }
}