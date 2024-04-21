#include<bits/stdc++.h>
using namespace std;
int  ans=0;
int n;

bool check(vector<int> &v,int len){
    int x=v[len],y=len;
    for(int i=y-1,j=x-1;i>=1 && j>=1;i--,j--){
        if(v[i]==j){
            return false;
        }
    }
    for(int i=y-1,j=x+1;i>=1 && j<=n;i--,j++){
        if(v[i]==j){
            return false;
        }
    }
    return true;
}

void letsgo(int len,vector<int> &v,vector<int> &used){
    if(len<=n){
        for(int i=1;i<=n;i++){
            if(!used[i]){
                used[i]=true;
                v[len]=i;
                if(check(v,len)){
                    letsgo(len+1,v,used);
                }
                used[i]=false;
            }
        }
    }
    else{
        ans++;
    }
}
int main(){
    cin>>n;
    vector<int> tmp(n+1);
    vector<int> used(n+1);
    letsgo(1, tmp, used);
    cout<<ans;
    return 0;
}