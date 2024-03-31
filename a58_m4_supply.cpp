#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    priority_queue<pair<int,pair<int,int>>> pq;
    while(k--){
        int d,e,l;
        cin>>d>>e>>l;
        pq.push({-d,{e,l}});
    }
    queue<int> rq;
    queue<int> aq;
    while(!pq.empty()){
        pair<int,pair<int,int>> u = pq.top();
        pq.pop();
        int e=u.second.first,l=u.second.second;
        if(e==0){
            aq.push(l);
            if(!rq.empty()){
                cout<<rq.front()<<'\n';
                rq.pop();
                aq.pop();
            }
            else{
                cout<<0<<'\n';
            }
        }
        else if(e==1){
            rq.push(l);
            if(!aq.empty()){
                cout<<aq.front()<<'\n';
                aq.pop();
                rq.pop();
            }
            else{
                cout<<0<<'\n';
            }
        }
    }
}