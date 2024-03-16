#include<bits/stdc++.h>
using namespace std;
int n,ans=0;

void letsgo(int len,vector<int> &v,int k,int m){
    if(len<n){
        v[len]=0;
        letsgo(len+1,v,k,m);
        v[len]=1;
        letsgo(len+1,v,k,m);
    }
    else{
        int tmp=v[0],c=1;
        for(int i=1;i<n;i++){
            if(v[i]==tmp){
                c++;
                if(c>m){
                    return ;
                }
            }
            else{
                tmp=v[i];
                k--;
                c=1;
            }
        }
        if(k==0){
            ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    letsgo(1,v,k,m);
    cout<<ans;
    
}