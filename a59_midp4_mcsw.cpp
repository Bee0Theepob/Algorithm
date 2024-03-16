#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,a,k;
    cin>>n>>k;
    vector<long long> v;
    cin>>a;
    v.push_back(a);
    for(int i=1;i<n;i++){
        cin>>a;
        v.push_back(v[v.size()-1]+a);
    }
    long long ans=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=1;j<min(k,n-i);j++){
            ans=max(ans,v[i+j]-v[i]);
        }
    }
    cout<<ans;
}