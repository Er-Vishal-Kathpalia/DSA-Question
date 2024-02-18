#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int singleNumber(vector<int>& nums){

    int ans = nums[0];
    for(int i=1;i<nums.size();i++){
        ans = ans^nums[i];
    }
    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<singleNumber(nums)<<endl;

    return 0;
}

/*


*/