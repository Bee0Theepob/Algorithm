#include <bits/stdc++.h>
using namespace std;
vector<int> rev;
vector<int> rever(vector<int> v,int start,int stop){
    vector<int> result;
    for(int i=0;i<start;i++){
        result.push_back(v[i]);
    }
    for(int i=stop-1;i>=start;i--){
        result.push_back(v[i]);
    }
    for(int i=stop;i<v.size();i++){
        result.push_back(v[i]);
    }
    return result;
}

bool check(vector<int> v,int start,int stop){
    if(stop-start==2){
        return  v[start]==0 && v[start+1]==1;
    }
    else{
        int m=(start+stop)/2;
        return (check(v,start,m) || check(rever(v,start,m),start,m)) && check(v,m,stop);
    }
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k,ch;
    cin>>n>>k;
    while(n--){
        vector<int> dna(pow(2,k));
        for(int i=0;i<pow(2,k);i++){
            cin>>dna[i];
        }
        if(check(dna,0,pow(2,k))){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}