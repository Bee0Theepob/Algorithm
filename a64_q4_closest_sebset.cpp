#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> v;
int ans=1e9;
void letsgo(int len,int c,int sum){
    if(len<n){
        if(n-len-c>0) {
            letsgo(len+1,c,sum);
        }
        if(c>0){
            letsgo(len+1,c-1,sum+v[len]);
        }
    }
    else{
        ans=min(ans,abs(k-sum));
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    letsgo(0,m,0);
    cout<<ans;
    return 0;
}