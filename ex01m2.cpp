#include <bits/stdc++.h>
using namespace std;

int ans=0;

void merge(vector<int> &v,int start, int m, int stop,vector<int> &tmp) {
    int bi = start;
    int ci = m+1;
    for (int i = start; i<= stop;i++) {
        if (ci > stop) { 
            tmp[i] = v[bi++]; 
            continue; 
        }
        if (bi > m) {
            tmp[i] = v[ci++]; 
            continue; 
        }
        if(v[bi]>v[ci]){
            tmp[i]=v[ci++];
            ans+=(m-bi+1);
        }
        else{
            tmp[i]=v[bi++];
        }
    }
    for (int i = start; i<= stop;i++) v[i] = tmp[i];

}

void sth_like_msort(vector<int> &v,int start,int stop,vector<int> &tmp){
    
    if(start<stop){
        int m=(start+stop)>>1;
        sth_like_msort(v,start,m,tmp);
        sth_like_msort(v,m+1,stop,tmp);
        merge(v,start,m,stop,tmp);
    }
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,a;
    cin>>t;
    vector<int> v(t),tmp(t);
    for(int i=0;i<t;i++){
        cin>>v[i]; 
    }
    sth_like_msort(v,0,v.size()-1,tmp);
    cout<<ans;
}