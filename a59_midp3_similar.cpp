#include <bits/stdc++.h>
using namespace std;

string slide(string s,int l,int r){
    string result="";
    for(int i=l;i<r;i++){
        result+=s[i];
    }
    return result;
}

bool simi(string a,string b){
    if(a==b){
        return true;
    }
    if(a.size()==1){
        return false;
    }
    else{
        int m = a.size()/2;
        string a1=slide(a,0,m);
        string a2=slide(a,m,a.size());
        string b1=slide(b,0,m);
        string b2=slide(b,m,a.size());
        bool case1 = simi(a1,b1) && simi(a2,b2);
        bool case2 = simi(a1,b2) && simi(a2,b1);
        return case1||case2; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    bool check = simi(a,b);
    if(check){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

}