#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> g;
vector<bool> burned;
vector<int> b;
int allbea=0;
void fire(int a,int from){
    burned[a]=true;
    allbea-=b[a];
    b[a]=0;
    for(int x:g[a]){
        if(x==from){
            continue;
        }
        if(!burned[x]){
            
            fire(x,a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    burned.resize(n);
    b.resize(n);
    vector<int> ks(k);
    for(int i=0;i<n;i++){
        cin>>b[i];
        allbea+=b[i];
    }
    for(int i=0;i<k;i++){
        cin>>ks[i];
    }
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        g[p].push_back(q);
    }
    for(int i=0;i<k;i++){
        fire(ks[i],-1);
        cout<<allbea<<' ';
    }   
}