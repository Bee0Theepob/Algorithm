#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    vector<vector<int>> ans(n,vector<int>(n)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>v[i][j];
        }
    }
    ans[0][0]=v[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            ans[i][j]=max(ans[i][j],ans[i-1][j]+v[i][j]);
            if(j-1>=0){
                ans[i][j]=max(ans[i-1][j-1]+v[i][j],ans[i][j]);
            }
        }
    }
    int maxx=0;
    for(int i=0;i<n;i++){
        maxx=max(maxx,ans[n-1][i]);
    }
    cout<<maxx;
}