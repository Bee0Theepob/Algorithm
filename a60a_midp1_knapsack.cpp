#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    n++;m++;
    vector<int> v;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> w;
    for(int i=1;i<m;i++){
        int x;
        cin>>x;
        w.push_back(x);
    }
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dp[i][j];
        }
    }
    int i=n-1,j=m-1;
    vector<int> ans;
    while(dp[i][j]!=0){
        if(dp[i][j]==max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1])){
            ans.push_back(i+1);
        }
        else{
            i--;
        }
    }
    cout<<ans.size()<<'\n';
    for(int x:ans){
        cout<<x<<' ';
    }

}