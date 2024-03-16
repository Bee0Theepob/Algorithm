#include<bits/stdc++.h>
using namespace std;
map<int ,int> mp;
int f(int n){
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    if(n==0 || n==1){
        mp[n]=n;
        return n;
    }
    else{
        int ans=f(n-1)+f(n-2);
        mp[n]=ans;
        return ans;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    cout<<f(n);
}