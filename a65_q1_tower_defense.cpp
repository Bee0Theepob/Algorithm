#include <iostream>
#include <vector>
#include<map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k,w,h,ans=0;
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
        ans+=h;
    }
    for(int i=0;i<k;i++){
        cin>>h;
        t.push_back(h);
    }

    for(int i=0;i<k;i++){
        auto it=mp.lower_bound(t[i]-w);
        if(it!=mp.end() && it->first<=t[i]+w){
            mp[it->first]--;
            ans--;
            if(mp[it->first]==0){
                mp.erase(it);
            }
        }
    }

    cout<<ans;
}