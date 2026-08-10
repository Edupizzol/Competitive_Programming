//worth noting: this question is for some reason only on leetocode premium (it isn´t even that hard tho, so you will not find it on leetcode, but for sure will find on the internet)
#include <bits/stdc++.h>
using namespace std;

long long connect_ropes(vector<int> &v){
    priority_queue<int, vector<int>, greater<int>> minHeap(v.begin(),v.end());  
    long long total=0;

    while(minHeap.size()>1){
        int newElement=minHeap.top();
        total+=minHeap.top(); minHeap.pop();
        newElement+=minHeap.top();
        total+=minHeap.top(); minHeap.pop();
        minHeap.push(newElement);
    }

    return total;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int &x:v) cin>>x;
    cout<<connect_ropes(v)<<endl;
}