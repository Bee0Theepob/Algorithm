#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
void letsgo(int len,vector<int> &path,vector<bool> &visited,vector<vector<int>> &weights,int sumpath){
    if(len<n){
        for(int i=2;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                path[len]=i;
                letsgo(len+1,path,visited,weights,sumpath+weights[path[len-1]][path[len]]);
                visited[i]=false;
            }
        }
    }
    else{
        if(sumpath+weights[path[n-1]][path[n]]>ans){
            ans=sumpath+weights[path[n-1]][path[n]];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    vector<vector<int>> weights(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>weights[i][j];
        }
    }
    vector<int> path(n+1);
    vector<bool> visited(n+1);
    path[1]=1;
    path[n]=n;
    visited[1]=true;
    visited[n]=true;
    letsgo(2,path,visited,weights,0);
    cout<<ans;
    return 0;
}