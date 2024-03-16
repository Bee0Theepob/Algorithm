#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,sum=0,min=INT_MAX;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int maxx=v[0],tmp=v[0];
    for(int i=1;i<n;i++){//find max
        tmp=max(tmp+v[i],v[i]);
        maxx=max(maxx,tmp);
    }

    int minn=v[0];
    tmp=v[0];
    bool trig=false;
    for(int i=0;i<n;i++){
        if(tmp+v[i]<v[i]){
            tmp=tmp+v[i];
        }
        else{
            tmp=v[i];
            trig=true;
        }
        minn=std::min(minn,tmp);
    }
    int ans;
    if(trig){
        ans=max(maxx,sum-minn);
    }
    else{
        ans=maxx;
    }
    cout<<ans;
}

// 1 -2 -3 1 1 -2 -3 1