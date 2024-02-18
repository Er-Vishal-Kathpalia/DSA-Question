#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& v) {
    int n = v.size();
    int ans = INT_MIN;
    int cs = 0;
    int startIndex = 0;
    for(int i=0;i<(2*n-1);i++){
        cs += v[i%n];
        while( (i-startIndex > n-1 || v[startIndex%n] < 0) && startIndex <= i){
            cs -= v[startIndex%n];
            startIndex++;
        }
        cout<<"start index - "<<startIndex<<" cs - "<<cs<<endl;
        ans = max(ans,cs);
        if(cs<0) {
            cs = 0;
            startIndex = i + 1;
        }
    }
    return ans;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;

        vector<int> v;

        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }

        
        cout<<maxSubarraySumCircular(v)<<endl;
    }
}