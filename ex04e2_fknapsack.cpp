#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    double mw;
    int n;
    cin>>mw>>n;
    vector<pair<double,pair<double,double>>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second.first;
        v[i].first=v[i].second.first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second.second;
        v[i].first/=-v[i].second.second;
    }
    sort(v.begin(),v.end());
    double ans=0;
    int i=0;
    for(i=0;i<n;i++){
        if(mw-v[i].second.second>=0){
            mw-=v[i].second.second;
            ans+=v[i].second.first;
        }
        else{
            ans+=-v[i].first*(mw);
            break;
        }
    }
    cout << fixed 
         << setprecision( 
                numeric_limits<double>::max_digits10) 
         << ans << endl;

}
