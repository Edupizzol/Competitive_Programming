#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c;
    cin>>a>>b>>c;
    int m;
    cin>>m;
    vector<long long> USB;
    vector<long long> PS2;

    for(int i=0;i<m;i++){
        long long n;
        string s;
        cin>>n; cin>>s;
        if(s=="USB") USB.push_back(n);
        else PS2.push_back(n);
    }

    sort(USB.begin(),USB.end(), greater<long long>());
    sort(PS2.begin(),PS2.end(),greater<long long>());
    int USBend = USB.size()-1;
    int PS2end=PS2.size()-1;
    long long count=0; long long cost=0;
    while(a>0 && USB.size()>0){
        count++; cost+=USB[USBend--]; USB.pop_back(); a--;
    }
    while(b>0 && PS2.size()>0){
        count++; cost+=PS2[PS2end--]; PS2.pop_back(); b--;
    }
    while(c>0 && USB.size()>0 && PS2.size()>0){
        count++;
        if(PS2[PS2.size()-1]>USB[USB.size()-1]){
            cost+=USB[USB.size()-1];USB.pop_back(); 
        }
        else{
            cost+=PS2[PS2.size()-1];PS2.pop_back(); 
        }   
        c--;
    }

    if(c>0){
        if(PS2.size()>0){
            while(c>0 && PS2.size()>0){
                count++;cost+=PS2[PS2.size()-1];PS2.pop_back();c--;
            }
        }
        else{
            while(c>0 && USB.size()>0){
                count++;cost+=USB[USB.size()-1];USB.pop_back();c--;
            }
        }
    }

    cout<<count<<" "<<cost<<endl;
    return 0;
}