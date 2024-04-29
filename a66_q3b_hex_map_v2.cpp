#include<bits/stdc++.h>
using namespace std;
int rr,cc;
void dijk(int str,int stc ,vector<vector<int>> &dist,vector<vector<int>> &weights){
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{str,stc}});
    dist[str][stc]=weights[str][stc];
    while(!pq.empty()){
        int r=pq.top().second.first,c=pq.top().second.second;
        pq.pop();
        if(r%2==1){
            int dc[]={-1,1,0,1,0,1},dr[]={0,0,-1,-1,1,1};
            for(int i=0;i<6;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr<1 || nr>rr || nc<1 || nc>cc) continue;

                if(dist[nr][nc] > dist[r][c] + weights[nr][nc]){
                    dist[nr][nc] = dist[r][c] + weights[nr][nc];
                    pq.push({-dist[nr][nc],{nr,nc}});
                }
            }
        }
        else{
            int dc[]={-1,1,-1,0,-1,0},dr[]={0,0,-1,-1,1,1};
            for(int i=0;i<6;i++){
                int nr=r+dr[i],nc=c+dc[i];

                if(nr<1 || nr>rr || nc<1 || nc>cc) continue;

                if(dist[nr][nc] > dist[r][c] + weights[nr][nc]){
                    dist[nr][nc] = dist[r][c] + weights[nr][nc];
                    pq.push({-dist[nr][nc],{nr,nc}});
                }
            }
        }
    }

} 

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int str,stc,er,ec;
    cin>>rr>>cc>>str>>stc>>er>>ec;
    vector<vector<int>> weights(rr+1,vector<int>(cc+1));
    for(int i=1;i<=rr;i++){
        for(int j=1;j<=cc;j++){
            cin>>weights[i][j];
        }
    }
    vector<vector<int>> dist(rr+1,vector<int>(cc+1,1e9));
    dijk(str,stc,dist,weights);
    cout<<dist[er][ec];
    return 0;
}

