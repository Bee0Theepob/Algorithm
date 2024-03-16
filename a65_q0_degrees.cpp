#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,a,maxx=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            v[i]+=a;
            v[j]+=a;
        }
    }
    for(int i=0;i<n;i++){
        v[i]/=2;
        if(maxx<v[i]){
            maxx=v[i];
        }
    }

    map<int,int> m;
    for(auto x:v){
        m[x]++;
    }
    for(int i=0;i<maxx+1;i++){
        cout<<m[i]<<' ';
    }
}