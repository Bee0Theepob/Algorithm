#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int jump(int n){
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    if(n==0){
        return mp[n]=v[0];
    }
    if(n==1){
        return mp[n]=v[0]+v[1];
    }
    if(n==2){
        return mp[n]=max(v[0]+v[1]+v[2],v[0]+v[2]);
    }
    return mp[n]=max(max(jump(n-1)+v[n],jump(n-2)+v[n]),jump(n-3)+v[n]);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,a;
    cin>>n;
    v.resize(n);
    vector<long long> ans(n+10,INT_MIN);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<jump(n-1);
    

}