#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    dp[0][0]=v[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j-1>=0){
                dp[i][j]=max(dp[i][j],dp[i][j-1]+v[i][j]);
            }
            if(i-1>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+v[i][j]);
            }
            if(i-1>=0 && j-1>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2*v[i][j]);
            }
        }
    }
    cout<<dp[n-1][m-1];
}