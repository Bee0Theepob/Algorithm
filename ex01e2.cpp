#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,ans=INT_MIN;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //int maxx=v[0],tmp=v[0];
    // for(int i=1;i<n;i++){
    //     tmp=max(v[i],tmp+v[i]);
    //     maxx=max(maxx,tmp);
    // }
    // cout<<maxx;
    int maxi;
    int maxj,tmp;
    for(int i=0;i<n;i++){
        maxi=v[i];
        maxj=v[i];
        tmp=v[i];
        for(int j=i+1;j<n;j++){
            maxj=maxj+v[j];
            if(maxj>tmp){
                tmp=maxj;
            }
        }
        if(tmp>ans){
            ans=tmp;
        }
    }
    cout<<ans;
}