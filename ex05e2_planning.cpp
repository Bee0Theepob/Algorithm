#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
queue<int> q;

void letsgo(vector<int> &indeg){
    while(!q.empty()){
        int u=q.front();q.pop();
        if(indeg[u]==0){
            cout<<u<<' ';
            for(int i=0;i<g[u].size();i++){
                indeg[g[u][i]]--;
                if(indeg[g[u][i]]==0){
                    q.push(g[u][i]);
                }
            }
        }
        else{
            q.push(u);        
            }

    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a;
    cin>>n;
    g.resize(n);
    vector<int> indeg(n);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        indeg[i]=t;
        if(t==0){
            q.push(i);
        }
        for(int j=0;j<t;j++){
            cin>>a;
            g[a].push_back(i);
        }
    }
    letsgo(indeg);


    return 0;
}