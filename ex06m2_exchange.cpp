#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        bool trig=false;
        int n;
        cin>>n;
        vector<vector<double>> weight(n+1,vector<double>(n+1));
        vector<vector<double>> ans(n+1,vector<double>(n+1));
        vector<pair<int,int>> edges;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>weight[i][j];
                edges.push_back({i,j});
            }
        }
        for(int i=0;i<=n;i++){
            ans[1][i]=weight[1][i];
            ans[i][0]=1;
            ans[0][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(pair<int,int> p:edges){
                int a=p.first,b=p.second;
                if(ans[i][b] < ans[i-1][a] * weight[a][b]){
                    ans[i][b] = ans[i-1][a] * weight[a][b];
                }
            }
        }
        for(pair<int,int> p:edges){
            int a=p.first,b=p.second;
            if(ans[n][b] < ans[n][a] * weight[a][b]){
                trig=true;
            }
        }
        if(trig){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
    return 0;
}