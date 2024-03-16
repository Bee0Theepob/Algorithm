#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int getSum(int l,int r){
    return v[r]-v[l-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,t;
    cin>>n;
    int maxx=INT_MIN;
    v.resize(n+1);
    v[0]=0;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>t;
        v[i+1]=v[i]+t;
        mp[t].push_back(i+1);
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        vector<int> tmp=it->second;
        for(int i=0;i<tmp.size()-1;i++){
            for(int j=i;j<tmp.size();j++){
                maxx=max(maxx,getSum(tmp[i],tmp[j]));
            }
            
        }
        
    }
    cout<<maxx<<'\n';
    return 0;
}