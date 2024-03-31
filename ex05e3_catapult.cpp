#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> g;
int letsgo(int a,int start,int from,vector<int> &visited,vector<int> path,vector<int> &best_path){
    visited[a]=true;
    path.push_back(a);
    for(int x:g[a]){
        if(g.find(x)==g.end()){
            continue;
        }
        if(x==start){
            if(path.size()>best_path.size()){
                best_path=path;
            }
            break;
        }
        if(x==from){
            continue;
        }

        if(!visited[x]){
            int result = letsgo(x,start,a,visited,path,best_path);
            visited[x]=false;
            return result;
        }
    }
    return best_path.size();
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        g[i];
        int t,a;
        cin>>t;
        while(t--){
            cin>>a;
            g[i].push_back(a);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        vector<int> visited(n);
        vector<int> path,best_path={i};
        if(g.find(i)!=g.end()){
            ans.push_back(letsgo(i,i,-1,visited,path,best_path));
        }
        for(int &b:best_path){
            g.erase(b);
        }
    }
    sort(ans.begin(),ans.end());
    for(int &x:ans){
        cout<<x<<' ';
    }

    return 0;
}