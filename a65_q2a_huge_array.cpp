#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q,a,b;
    cin>>n>>q;
    map<int,int> m;
    vector<pair<int,int>> ans;
    while(n--){
        cin>>a>>b;
        m[a]+=b;
    }
    ans.push_back({0,0});
    for(auto x:m){
        ans.push_back({x.second+ans[ans.size()-1].first,x.first});
    }

    while(q--){
        cin>>a;
        auto it=lower_bound(ans.begin(),ans.end(),make_pair(a,0));
        cout<<it->second<<'\n';
    }

}