#include<bits/stdc++.h>
using namespace std;
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    int rc = 1000;
    vector<vector<int>> v(rc + 10,vector<int>(rc + 10));
    vector<vector<int>> u(rc + 10,vector<int>(rc + 10,1e9));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[y][x]=1;
    }
    vector<int> dx={-1,0,1,0},dy={0,-1,0,1};
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    u[b][a]=0;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i] , ny=y+dy[i];
            if(nx >= 0 && nx<=rc+1 && ny>=0 && ny<=rc+1 && u[ny][nx]>u[y][x]+v[ny][nx]){
                q.push(make_pair(nx,ny));
                u[ny][nx]=u[y][x]+v[ny][nx];
            }
        }
    }
    // for(vector<int> vec:u){
    //     for(int x:vec){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int i = 1; i <= 10; i++) {
    //     for(int j = 1; j <= 10; j++) {
    //         cout << u[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout<<u[0][0];
    return 0;
}