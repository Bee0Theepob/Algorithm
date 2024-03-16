#include <iostream>
#include<vector>
using namespace std;
vector<int> v;
int letsgo(int l,int r,int t){
    int m;
    while(l<r){
        m=(l+r)/2;
        if(v[m]>=t){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    return l;
}   

int main() {
    int n,q,t;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    while(q--){
        cin>>t;
        int idx=letsgo(0,n,t);
        if(v[idx]==t){
            cout<<t;
        }
        else if(idx!=0){
            cout<<v[idx-1];
        }
        else{
            cout<<-1;
        }
        cout<<'\n';
        
    }
}
