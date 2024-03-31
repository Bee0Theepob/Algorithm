#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    vector<int> dp(t+2);
    vector<pair<int,int>> v(t+1);
    for(int i=1;i<=t;i++){
        cin>>v[i].first;
    }
    for(int i=1;i<=t;i++){
        cin>>v[i].second;
    }
    sort(v.begin(),v.end());
    dp[t]=1;
    for(int i=t-1;i>0;i--){
        auto it=lower_bound(v.begin(),v.end(),make_pair(v[i].second,0));
        if(it==v.end()){
            dp[i]=dp[i+1];
        }
        else{
            dp[i]=max(dp[it-v.begin()]+1,dp[i+1]);
        }
    }
    cout<<dp[1];
}