#include<bits/stdc++.h>
using namespace std;
int r,c,k;
int bfs(pair<int,int> p,vector<vector<int>> &area,vector<vector<bool>> &visited){
    if(area[p.second][p.first]==1){
        return 0;
    }
    int ans=1;
    int dx[4]={-1,0,1,0},dy[]={0,-1,0,1};
    queue<pair<int,int>> q;
    q.push(p);
    visited[p.second][p.first]=true;
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        int x=u.first,y=u.second;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<=0 || nx>c || ny<=0 || ny>r || area[ny][nx]==1){
                continue;
            }
            if(!visited[ny][nx]){
                visited[ny][nx]=true;
                ans++;
                q.push({nx,ny});
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>r>>c>>k;
    vector<vector<int>> areaN(r+1,vector<int>(c+1));
    vector<vector<int>> areaS(r+1,vector<int>(c+1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>areaN[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>areaS[i][j];
        }
    }    
    vector<pair<int,int>> ks(k); 
    for(int i=0;i<k;i++){
        cin>>ks[i].second>>ks[i].first;
    }
    int ans=0;
    vector<vector<bool>> visited(r+1,vector<bool>(c+1));
    ans+=bfs({1,1},areaN,visited);
    int ans2=0;
    vector<vector<bool>> visited2(r+1,vector<bool>(c+1));
    for(pair<int,int> &p:ks){
        if(!visited2[p.second][p.first] && visited[p.second][p.first]){
            int a=bfs(p,areaS,visited2);
            ans2=max(ans2,a);
        }
    }
    cout<<ans+ans2;
    return 0;
}