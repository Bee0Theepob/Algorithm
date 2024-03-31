#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,set<pair<int,int>>> g;
vector<vector<int>> dist;
void letsgo(pair<int,int> a){
    queue<pair<int,int>> qq;
    qq.push(a);
    dist[a.first][a.second]=0;
    while(!qq.empty()){
      pair<int,int> p=qq.front();
      qq.pop();
      for(auto x:g[p]){
        if(dist[x.first][x.second]==-1){
          qq.push(x);
          dist[x.first][x.second]=dist[p.first][p.second]+1;
        }
      }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        vector<int> tmp(m,-1);
        dist.push_back(tmp);
    }
    for(int i=0;i<n;i++){
      cin>>v[i];
    }    
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='.'){
                    if(i>0 && v[i-1][j]=='.'){
                        g[make_pair(i,j)].insert(make_pair(i-1,j));
                        g[make_pair(i-1,j)].insert(make_pair(i,j));
                    }
                    if(j>0 && v[i][j-1]=='.'){
                        g[make_pair(i,j)].insert(make_pair(i,j-1));
                        g[make_pair(i,j-1)].insert(make_pair(i,j));
                    }
                    if(i<n-1 && v[i+1][j]=='.'){
                        g[make_pair(i,j)].insert(make_pair(i+1,j));
                        g[make_pair(i+1,j)].insert(make_pair(i,j));
                    }
                    if(j<m-1 && v[i][j+1]=='.'){
                        g[make_pair(i,j)].insert(make_pair(i,j+1));
                        g[make_pair(i,j+1)].insert(make_pair(i,j));
                    }
                }
            }
    }
 
    letsgo({0,0});
    if(dist[n-1][m-1]){
        cout<<dist[n-1][m-1];
    }
    else{
      cout<<-1;
    }
    cout<<"\n";
}