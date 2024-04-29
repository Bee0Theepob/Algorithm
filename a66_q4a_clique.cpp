#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
vector<vector<bool>> f;
vector<int> power;
bool check(vector<bool> get,int n){
    for(int i=1;i<=n;i++){
        if(get[i]){
            for(int j=i+1;j<=n;j++){
                if(get[j]){
                    if(!(f[i][j])) return false;
                }
            }
        }
    }
    return true;
}

void letsgo(int len,vector<bool> &get,int sum){
    if(len<=n){
        get[len]=1;
        if(check(get,len)){
            letsgo(len+1,get,sum+power[len]);
        }
        get[len]=0;
        if(check(get,len)){
            letsgo(len+1,get,sum);
        }
    }
    else{
        ans=max(ans,sum);
        }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    power.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>power[i];
    }
    f.resize(n+1);
    for(int i=1;i<=n;i++){
        f[i].push_back(0);
        for(int j=1;j<=n;j++){
            int a;cin>>a;
            f[i].push_back(a);
        }   
    }

    vector<bool> get(n+1);
    letsgo(1,get,0);
    cout<<ans;
    return 0;
}

