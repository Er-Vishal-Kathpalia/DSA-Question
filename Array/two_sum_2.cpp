#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> twoSum(vector<int>& numbers, int target){
    int s = 0;
    int e = numbers.size()-1;

    while(s<=e){
        int num = numbers[s] + numbers[e];
        if( num==target ){
            return {s+1,e+1};
        } else if( num>target ){
            e--;
        } else if( num<target ){
            s++;
        }
    }
    return {-1,-1};
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
    int target;
    cin>>target;
    vector<int> ans = twoSum(nums, target);
    print(ans);
    return 0;
}

/*


*/