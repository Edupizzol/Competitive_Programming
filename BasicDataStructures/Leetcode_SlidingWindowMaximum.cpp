#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> v;
    deque<int> dq;

    for(int i=0;i<nums.size();i++){
        while(!dq.empty() && nums[i]>nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(dq.front()<=i-k) dq.pop_front();  
        if(i>=k-1) v.push_back(nums[dq.front()]);
    }

    return v;

}

int main(){

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int& x:v) cin>>x;
    vector<int> ans = maxSlidingWindow(v,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}