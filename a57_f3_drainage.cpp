#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,l;
    cin>>n>>l;
    if(l==1){
        cout<<n;
        return 0;
    }
    vector<int> hole(n);
    for(int i=0;i<n;i++){
        cin>>hole[i];
    }
    sort(hole.begin(),hole.end());
    int ans=1;
    auto it=lower_bound(hole.begin(),hole.end(),hole[0]+l);
    while(it!=hole.end()){
        ans++;
        it=lower_bound(hole.begin(),hole.end(),*it+l);
    }
    cout<<ans;
}
