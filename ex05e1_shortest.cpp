#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> mapp;
vector<vector<int>> dist;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int r,c;
void dijk(int stx,int sty){
  priority_queue<pair<int,pair<int,int>>> pq;
  pq.push({0,{stx,sty}});
  dist[sty][stx]=0;
  while(!pq.empty()){
    int x=pq.top().second.first,y=pq.top().second.second;
    pq.pop();

    for(int i=0;i<4;i++){
      int nx=x+dx[i],ny=y+dy[i];
      if(nx<0 || nx>=c || ny<0 || ny>=r || mapp[ny][nx]=='#') continue;

      if(dist[ny][nx] > dist[y][x] + 1){
        dist[ny][nx] = dist[y][x] + 1;
        pq.push({-dist[ny][nx],{nx,ny}});
      }
    }
  }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    char t;
    cin>>r>>c;
    mapp.resize(r);
    dist.resize(r);
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin>>t;
        mapp[i].push_back(t);;
        dist[i].push_back(1e9);
      }
    }
    dijk(0,0);
    if(dist[r-1][c-1]!=1e9){
      cout<<dist[r-1][c-1];
    }
    else{
      cout<<-1;
    }
    
}