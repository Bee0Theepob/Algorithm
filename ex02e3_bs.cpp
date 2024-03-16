#include <bits/stdc++.h>

using namespace std;

int wowo(vector<int> &v,int &target,int start ,int stop){
    int m=(start+stop)/2;
    while(start <= stop){
        if(v[m] > target){
            stop=m-1;
        }
        else{
            start=m+1;
        }
        m=(start+stop)/2;
    }  
    if(target<v[m]){
        return -1;
    }
    return m ;
}   

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q,t;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    while(q--){
        cin>>t;
        cout<<wowo(v,t,0,v.size()-1)<<'\n';
    }
}