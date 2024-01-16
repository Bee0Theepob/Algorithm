#include <iostream>
#include <vector>
#include<map>
#include<set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k,w,h;
    map<int ,int> mp;
    cin>>n>>m>>k>>w;
    vector<int> p(n);
    vector<int> t;
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        cin>>h;
        mp[p[i]]+=h;
    }
    for(int i=0;i<k;i++){
        cin>>h;
        t.push_back(h);
    }

    for(int i=0;i<k;i++){
        auto it=mp.lower_bound(t[i]-w);
        if(it!=mp.end() && it->first<=t[i]+w){
            mp[it->first]--;
            if(mp[it->first]==0){
                mp.erase(it);
            }
        }
    }
    int ans=0;
    for(auto x:mp){
        ans+=mp[x.first];
    }
    cout<<ans;
}