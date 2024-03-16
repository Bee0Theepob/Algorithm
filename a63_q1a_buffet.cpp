#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k;
    cin>>n>>k>>m;
    vector<int> v(n+5),summ(n+1),deli(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        summ[i]=summ[i-1]+v[i];
        deli[i]=summ[i]-(i*m);
    }
    // for(auto x:summ){
    //     cout<<x<<" ";
    // }
    // cout<<'\n'<<"----------------------------\n";
    // for(auto x:deli){
    //     cout<<x<<" ";
    // }
    // cout<<'\n'<<"----------------------------\n";

    while(k--){
        int a,b;
        cin>>a>>b;
        auto it = lower_bound(deli.begin(),deli.end(),b+deli[a]);
        if(it!=deli.begin()){
            it--;
        }
        cout<<it-deli.begin()<<'\n';
    }
}
