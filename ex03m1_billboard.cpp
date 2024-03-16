#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int finddd(vector<int> &v,int n){
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    if(n==0){
        return mp[n]=v[0];
    }
    else if(n==1){
        return mp[n]=max(v[0],v[1]);
    }
    else if(n==2){
        return mp[n]=max(v[2],max(v[0],v[1]));
    }
    return mp[n]=max(finddd(v,n-1),max(finddd(v,n-3)+v[n],finddd(v,n-2)));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<finddd(v,n-1);
}
