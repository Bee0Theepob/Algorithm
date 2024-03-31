#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> pan; 
int r,c,t;
void spread(vector<vector<int>> &v,vector<vector<int>> &visited){
        int a=pan.size();
        while(a--){
        pair<int,int> p=pan.front();
        pan.pop();
        int y=p.first,x=p.second;
        if(y>0 && v[y-1][x]!=2 && !visited[y-1][x]){
            visited[y-1][x]=true;
            pan.push(make_pair(y-1,x));
            v[y-1][x]=1;
        }
        if(x>0 && v[y][x-1]!=2 && !visited[y][x-1]){
            visited[y][x-1]=true;
            pan.push(make_pair(y,x-1));
            v[y][x-1]=1;
        }
        if(y<r-1 && v[y+1][x]!=2 && !visited[y+1][x]){
            visited[y+1][x]=true;
            pan.push(make_pair(y+1,x));
            v[y+1][x]=1;
        }
        if(x<c-1 && v[y][x+1]!=2 && !visited[y][x+1]){
            visited[y][x+1]=true;
            pan.push(make_pair(y,x+1));
            v[y][x+1]=1;
        }
    }
}

int main(){
    cin>>r>>c>>t;
    vector<vector<int>> v(r,vector<int>(c));
    vector<vector<int>> visited(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
            if(v[i][j]==1){
                pan.push(make_pair(i,j));
                visited[i][j]=true;
            }
        }
    }
    while(t--){
        spread(v,visited);
    }
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j]==1){
                ans++;
            }
        }
    }
    cout<<ans;

}