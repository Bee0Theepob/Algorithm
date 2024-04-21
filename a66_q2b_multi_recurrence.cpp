#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
vector<int> ps;
vector<int> ans;
int r(int n,int k,vector<vector<int>> &b,vector<bool> &have){
    if(n<=0){
        return 0;
    }
    if(have[n]){
        return ans[n];
    }
    else if(n>0 && n<=k){
        have[n]=true;
        return ans[n]=a[n];
    }
    int t=0;
    for(int i=1;i<=ps[n-k];i++){
        t+=((r(n-b[n-k][i],k,b,have))%32717)%32717;
    }
    have[n]=true;
    return ans[n]=t%32717;
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    vector<vector<int>> b(100000,vector<int>(1000));
    vector<bool> have(100000);
    a.resize(k+1);
    ans.resize(100000);
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    ps.resize(n-k+10);
    for(int i=1;i<n-k+1;i++){
        int p;
        cin>>p;
        ps[i]=p;
        for(int j=1;j<=p;j++){
            int x;
            cin>>x;
            b[i][j]=x;
        }

    }
    for(int i=1;i<=n;i++){
        cout<<r(i,k,b,have)<<' ';
    }
    return 0;
}