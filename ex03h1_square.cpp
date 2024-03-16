#include <bits/stdc++.h>
using namespace std;
int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int r,c;
    cin>>r>>c;
    vector<string> v;
    vector<vector<int>> dp(r+1,vector<int>(c+1));
    v.push_back("xxxxxxxxxxxxxxxxxxxxxxxx");
    for(int i=0;i<r;i++){
        string tmp;
        cin>>tmp;
        v.push_back("x"+tmp);
    }
    int ans=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(v[i][j]=='1'){
                if(dp[i-1][j]>0 && dp[i][j-1]>0 && dp[i-1][j-1]>0){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=0;
                }
            }
            else{
                dp[i][j]=0;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';

    for(vector<int> v: dp){
        for(int x: v){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
}
