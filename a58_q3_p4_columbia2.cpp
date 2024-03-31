#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fee;
vector<vector<vector<int>>> ans;
vector<int> dx={-1,0,1,0},dy={0,-1,0,1};
int r,c,t;
void letsgo(pair<int,int> p,vector<vector<vector<int>>> &ans){
    priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
    pq.push({{0,2},{p.first,p.second}});
    ans[2][0][0]=0;
    ans[1][0][0]=0;
    ans[0][0][0]=0;
    while(!pq.empty()){
        pair<pair<int,int>,pair<int,int>> u = pq.top();
        pq.pop();
        int x=u.second.first, y=u.second.second, tear=u.first.second;         
        for(int i=0;i<4;i++){
            int nx=x+dx[i] , ny=y+dy[i];
            if(nx<0 || nx>=c || ny<0 || ny>=r){
                continue;
            }

            if(ans[tear][ny][nx] > ans[tear][y][x] + fee[ny][nx]){//normal dijkstra
                ans[tear][ny][nx] = ans[tear][y][x] + fee[ny][nx];
                pq.push({{-ans[tear][ny][nx],tear},{nx,ny}});
            }

            if(tear>0){//use tear
                if(ans[tear-1][ny][nx] > ans[tear][y][x]){
                    ans[tear-1][ny][nx]=ans[tear][y][x];//free1
                    pq.push({{-ans[tear-1][ny][nx],tear-1},{nx,ny}});
                }
                for(int j=0;j<4;j++){
                    int nnx=nx+dx[j],nny=ny+dy[j];
                    if(nnx<0 || nnx>=c || nny<0 || nny>=r){
                        continue;
                    }
                    
                    if(ans[tear-1][nny][nnx] > ans[tear][y][x]){
                        ans[tear-1][nny][nnx]=ans[tear][y][x];//free2
                        pq.push({{-ans[tear-1][nny][nnx],tear-1},{nnx,nny}});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>r>>c;
    fee.resize(r);
    ans.resize(3);
    ans[0].resize(r);
    ans[1].resize(r);
    ans[2].resize(r);
    for(int i=0;i<r;i++){
        ans[0][i].resize(c);
        ans[1][i].resize(c);
        ans[2][i].resize(c);
        for(int j=0;j<c;j++){
            cin>>t;
            fee[i].push_back(t);
            ans[0][i][j]=1e9;
            ans[1][i][j]=1e9;
            ans[2][i][j]=1e9;
        }
    }
    letsgo({0,0},ans);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<min({ans[0][i][j],ans[1][i][j],ans[2][i][j]})<<' ';
            }
            cout<<'\n';
        }
    return 0;
}
