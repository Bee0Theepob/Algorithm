#include<bits/stdc++.h>
using namespace std;
string a,b;
map<pair<int,int>,int> mp;
int letsgo(int n,int m){
    if(mp.find({n,m})!=mp.end()){
        return mp[{n,m}];
    }
    if(n<=0 || m<=0 ){
        return mp[{n,m}]=0;
    }
    if(a[n-1]==b[m-1]){
        return mp[{n,m}]=letsgo(n-1,m-1)+1;
    }
    else{
        return mp[{n,m}]=max(letsgo(n-1,m),letsgo(n,m-1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>a>>b;
    cout<<letsgo(a.size(),b.size());
    
}