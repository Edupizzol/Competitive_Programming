#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    long long g;
    cin >> n >> g;

    vector<long long> v(n);
    for (long long &x : v) cin >> x;
    sort(v.begin(), v.end());

    int left = 0, right = n - 1;
    int gondolas = 0;

    while (left <= right){

        if(left < right && v[left] + v[right]<=g){
            left++;     
        }
        right--;       
        gondolas++;

    }

    cout<<gondolas<< endl;

}