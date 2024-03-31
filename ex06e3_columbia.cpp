#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int r,c;
void letsgo(pair<int,int> a,vector<vector<int>> &dist,vector<vector<int>> &area){
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,a});
    dist[a.first][a.second]=0;
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        int x=u.second.first,y=u.second.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 || nx>=c || ny<0 || ny>=r){
                continue;
            }

            if(dist[ny][nx] > dist[y][x] + area[ny][nx]){
                dist[ny][nx] = dist[y][x] + area[ny][nx];
                pq.push({-dist[ny][nx],{nx,ny}});
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>r>>c;
    vector<vector<int>> area(r,vector<int>(c));
    vector<vector<int>> dist(r,vector<int>(c,1e9));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>area[i][j];
        }
    }
    letsgo({0,0},dist,area);
    for(vector<int> v:dist){
        for(int x:v){
            cout<<x<<' ';
        }
        cout<<'\n';
    }

}