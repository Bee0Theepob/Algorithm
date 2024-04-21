#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mapp;
queue<pair<int,int>> q;
vector<vector<bool>> visited;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int n,m,t,a;
int ans=0;
void bfs1time(){
    int round = q.size();
    while(round--){
        int y=q.front().first,x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n || mapp[ny][nx]==2) continue;

            if(!visited[ny][nx]){
                visited[ny][nx]=true;
                q.push({ny,nx});
                mapp[ny][nx]=1;
                ans++;
            }
        }
    }
}

int main(){
    cin>>n>>m>>t;
    mapp.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            mapp[i].push_back(a);
            visited[i].push_back(0);
            if(a==1){
                q.push({i,j});
                visited[i][j]=1;
                ans++;
            }
        }
    }
    while(t--){
        bfs1time();
    }
    cout<<ans;
    return 0;
}