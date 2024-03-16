#include <bits/stdc++.h>
using namespace std;
vector<int> v;

long long finddd(long long l,long long r,long long q){
    if(l==r){
        return l;
    }
    else{
        long long m=(l+r)/2,sum=0;
        for(auto x:v){
            sum+=(m/x);
        }
        if(sum>=q){
            return finddd(l,m,q);
        }
        else{
            return finddd(m+1,r,q);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n,a,q;
    cin>>n>>a;
    for(int i=0;i<n;i++){
        cin>>q;
        v.push_back(q);
    }
    while(a--){
        cin>>q;
        cout<<finddd(0,1e12+10,q-n)<<'\n';
    }
}
