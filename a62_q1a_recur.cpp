#include<bits/stdc++.h>
using namespace std;
int a,b;
void make_mat(int x,int y,int a,int b,vector<vector<int>> &v,int step){
    if(a==0){
        cout<<b;
        exit(0);
    }
    if(a==1){
        v[y][x]=b;
        v[y][x+1]=b-1;
        v[y+1][x]=b+1;
        v[y+1][x+1]=b;
    }
    else{
        a-=1;
        make_mat(x-step,y-step,a,b,v,step/2);
        make_mat(x+step,y-step,a,b-1,v,step/2);
        make_mat(x-step,y+step,a,b+1,v,step/2);
        make_mat(x+step,y+step,a,b,v,step/2);
    }

}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>a>>b;
    int size=pow(2,a);
    vector<vector<int>> vec( pow(2,a) , vector<int> (pow(2,a)));
    make_mat(size/2-1,size/2-1,a,b,vec,size/4);
    for(vector<int> v:vec){
        for(int x:v){
            cout<<x<<' ';
        }
        cout<<"\n";
    }
}