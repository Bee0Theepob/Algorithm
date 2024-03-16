#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> v(n,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[i][j];
            v[i][j]+=v[i][j-1];
        }
    }
    int tx,ty,bx,by;
    while(q--){
        cin>>ty>>tx>>by>>bx;
        int ans=0;
        for(int i=ty;i<=by;i++){
            ans+=v[i][bx+1]-v[i][tx];
        }
        cout<<ans<<'\n';
    }
    
}