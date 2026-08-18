#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; 

    int t,room=0;
    cin>>t;
    vector<int> answer(t);
    queue<int> rooms_allowed;
    vector<tuple<int,int,int>> v(t);

    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        v[i] = {a, b, i};  
    }
    sort(v.begin(), v.end()); 

    for(int i=0;i<(int)v.size();i++){
        int a,b,idx;
        a=get<0>(v[i]); b=get<1>(v[i]); idx=get<2>(v[i]);

        if(minHeap.empty()){
            if(rooms_allowed.empty()){room++; answer[idx]=room; minHeap.push({b,room});}
            else{answer[idx]=rooms_allowed.front(); minHeap.push({b,rooms_allowed.front()}); rooms_allowed.pop();}
        }
        else{
            while(!minHeap.empty() && minHeap.top().first<a){
                rooms_allowed.push(minHeap.top().second);
                minHeap.pop();}

            if(rooms_allowed.empty()){
                room++;
                answer[idx]=room;
                minHeap.push({b,room});
            }
            else{
                answer[idx]=rooms_allowed.front();
                minHeap.push({b,rooms_allowed.front()});
                rooms_allowed.pop();
            }
        }
    }

    cout<<room<<endl;
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<" ";
    cout<<endl;

    return 0;
}