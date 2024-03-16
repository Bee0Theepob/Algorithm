#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,a;
    long long r,c;
    cin>>n>>m;
    map<pair<int,int>,int> mp;
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            cin>>a;
            mp[{i,j}]=a;
        }
    }
    map<pair<int,int>,int> mpT;
    mpT[{1,1}]=mp[{1,1}];
    mpT[{1,2}]=mp[{2,1}];
    mpT[{2,1}]=mp[{1,2}];
    mpT[{2,2}]=mp[{2,2}];
    while(m--){
        cin>>r>>c;
        int d=2;
        int checkr=0;
        while(r>=d+1){
            r-=d;
            d*=2;
            checkr=1-checkr;
        }
        d=2;
        int checkc=0;
        while(c>=d+1){
            c-=d;
            d*=2;
            checkc=1-checkc;
        }
        r%=3;c%=3;
        int factor=1;
        if(checkr==1){
            factor=-1;
        }
        int ans;
        if(checkc==1){
            ans=mpT[{r,c}];
        }
        else{
            ans=mp[{r,c}];
        }
        //cout<<ans*factor<<'\n';
        cout<<r<<' '<<c<<' '<<checkr<<' '<<checkc<<'\n';
    }
}