#include<bits/stdc++.h>
using namespace std;

int dis(pair<int,int> p1,pair<int,int> p2){
    return pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> v;
    while(n--){
        cin>>x>>y;
        v.push_back({x,y});
    }
    int ans=INT_MAX;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            ans=min(ans,dis(v[i],v[j]));
        }
    }
    cout<<ans;
}