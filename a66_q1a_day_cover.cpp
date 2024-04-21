#include<bits/stdc++.h>
using namespace std;
int maxx=INT_MAX;
void letsgo(int n,int len,vector<int> &v,vector<vector<int>> &stud,int k,int &m){
    if(len<=n){
        v[len]=0;
        letsgo(n,len+1,v,stud,k,m);
        if(k<maxx){
            v[len]=1;
            letsgo(n,len+1,v,stud,k+1,m);
        }
        
    }
    else{
        vector<bool> tmp(m+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(v[i]==1){
                ans++;
                for(int &j:stud[i]){
                    tmp[j]=true;
                }
            }
            bool check=true;
            for(int k=1;k<=m;k++){
                if(!tmp[k]){
                    check=false;
                    break;
                }
            }
            if(check){
                maxx=min(maxx,ans);
                break;
            }
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(m+1);
    int d;
    int t;
    for(int i=1;i<=m;i++){
        cin>>d;
        for(int j=1;j<=d;j++){
            cin>>t;
            v[i].push_back(t);
        }
    }
    vector<int> tmp(m+1);
    letsgo(m,1,tmp,v,0,n);
    cout<<maxx;
    return 0;
}