#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n;
    cin>>n;
    long long ans=3,t1=1,t2=1,t3=1;
    for(int i=1;i<n;i++){
        t2=(t1+t2)%100000007;
        t3=t2;
        t1=ans;
        ans=((t1+t2)%100000007+t3)%100000007;
    }
    cout<<ans;
}