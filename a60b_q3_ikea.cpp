#include<bits/stdc++.h>
using namespace std;
int n,e;
void letsgo(vector<int> indeg,vector<vector<int>> &g){
    int step;
    bool can = true;
    for(int i=0;i<n;i++){
        cin>>step;
        if(indeg[step]!=0){
            can=false;
        }
        else{
            for(int x:g[step]){
                indeg[x]--;
            }
        }
    }
    if(can){
        cout<<"SUCCESS\n";
    }
    else{
        cout<<"FAIL\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>n>>e;
    vector<vector<int>> g(n+1,vector<int>(n+1));
    vector<int> indeg(n+1);
    while(e--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    } 
    int t=5;
    while(t--){
        letsgo(indeg,g);
    }
    
}