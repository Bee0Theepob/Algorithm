#include <bits/stdc++.h>
using namespace std;
long long a,b;
vector<long long> avenger;
long long solve(long long start,long long stop){    
    long long cnt = upper_bound(avenger.begin(), avenger.end(), stop) - lower_bound(avenger.begin(), avenger.end(), start);
    if(cnt==0){
        return a;
    }
    long long w1= b*cnt*(stop-start+1),w2;
    if(start<stop){
        long long m=(start+stop)/2;
        w2=solve(start,m)+solve(m+1,stop);
        w1=min(w1,w2);
    }
    return w1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long p,k,t;
    cin>>p>>k>>a>>b;
    long long size=pow(2,p);
    for(long long i=0;i<k;i++){
        cin>>t;
        avenger.push_back(t);
    }
    sort(avenger.begin(),avenger.end());
    cout<<solve(1,size);
}