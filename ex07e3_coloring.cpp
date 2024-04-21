#include<bits/stdc++.h>
using namespace std;

int ans=INT_MAX;

bool check(int n,vector<vector<int>> &g,vector<int> &color){
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            if(color[g[i][j]]==color[i]){
                return false;
            }
        }
    }
    return true;
}

void letsgo(int n,int len,vector<vector<int>> &g,vector<int> &color){
    if(len<n){
        for(int i=0;i<n;i++){
            color[len]=i;
            if(check(len,g,color)){
                letsgo(n,len+1,g,color);
            }
        }
    }
    else{
        if(check(n,g,color)){
            set<int> tmp;
            for(int x:color){
                tmp.insert(x);
            }
            ans=min(ans,(int) tmp.size());
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(m==0){
        cout<<1;
        return 0;
    }
    // ans=n;
    vector<vector<int>> g(n);
    vector<int> color(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    } 
    letsgo(n,0,g,color);
    cout<<ans;
    return 0;
}