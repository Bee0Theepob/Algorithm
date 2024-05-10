#include<bits/stdc++.h>
using namespace std;
int tmp;
set<long long> s;
queue<pair<long long,int>> q;
void bfs(){
    while(!q.empty()){
        long long a=q.front().first;
        int cnt=q.front().second;
        q.pop();

        if(a==0){
            cout<<cnt;
            return ;
        }
        else{
            tmp=(a+1)%16777216;
            if(s.find(tmp)==s.end()){
                q.push({tmp,cnt+1});
            }
            tmp=(a*2)%16777216;
            if(s.find(tmp)==s.end()){
                q.push({tmp,cnt+1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n;
    cin>>n;
    q.push({n,0});
    s.insert(n);
    bfs();
}