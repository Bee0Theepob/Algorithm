#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool> mp;
bool check(vector<int> &v,int start ,int stop,vector<int> count){
    if(mp.find({start,stop})!=mp.end()){
        cout<<"hello555\n";
       return mp[{start,stop}];
    }
    if(stop-start==4){
        int m=(start+stop)/2;
        bool b=abs((count[stop]-count[m])-(count[m]-count[start]))<=1;
        mp[{start,stop}]=b;
        return b;
    }
    else{
        int m=(start+stop)/2;
        bool b=abs((count[stop]-count[m])-(count[m]-count[start]))<=1;
        b=b && check(v,start,m,count) && check(v,m,stop,count);
        mp[{start,stop}]=b;
        return b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    while(n--){
        mp.clear();
        int size=pow(2,k);
        vector<int> dna(size);
        vector<int> count;
        int c=0;
        count.push_back(0);
        for(int i=0;i<pow(2,k);i++){
            cin>>dna[i];
            if(dna[i]==1){
                c++;
            }
            count.push_back(c);
        }
        if(check(dna,0,size,count)){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}
