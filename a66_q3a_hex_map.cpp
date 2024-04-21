#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> weights;
int r,c;
void dijk(pair<int,int> a,vector<vector<int>> &dist){
    priority_queue<pair<int,pair<int,int>>> pq;
    dist[a.second][a.first]=weights[{a.second,a.first}];
    pq.push({0,{a.first,a.second}});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        int cost = -u.first;
        int x=u.second.first,y=u.second.second;
        if(x%2==1){
            vector<int> dx={0,0,-1,-1,1,1},dy={1,-1,-1,0,-1,0};
            for(int i=0;i<6;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<=0 || nx>c || ny<=0 || ny>r){
                    continue;
                }

                if(dist[ny][nx] > dist[y][x] + weights[{ny,nx}]){
                    dist[ny][nx] = dist[y][x] + weights[{ny,nx}];
                    pq.push({-dist[ny][nx],{nx,ny}});
                }
            }
        }
        else{
            vector<int> dx={0,0,-1,-1,1,1},dy={1,-1,0,1,0,1};
            for(int i=0;i<6;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<=0 || nx>c || ny<=0 || ny>r){
                    continue;
                }

                if(dist[ny][nx] > dist[y][x] + weights[{ny,nx}]){
                    dist[ny][nx] = dist[y][x] + weights[{ny,nx}];
                    pq.push({-dist[ny][nx],{nx,ny}});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>r>>c;
    int stx,sty,tx,ty;
    cin>>stx>>sty>>tx>>ty;
    vector<vector<int>> dist(r+1);
    for(int i=1;i<=r;i++){
        dist[i].push_back(1e9);
        for(int j=1;j<=c;j++){
            int a;
            cin>>a;
            weights[{i,j}]=a;
            dist[i].push_back(1e9);
        }
    }
    dijk({stx,sty},dist);
    cout<<dist[ty][tx];

    return 0;
}