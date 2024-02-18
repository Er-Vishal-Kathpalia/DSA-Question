#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool searchInMatix(vector<int> mat, int target){
    cout<<"here"<<endl;
    int s = 0;
    int e = mat.size()-1;

    while(s<=e){
        int mid = (s+e)/2;
        if( mat[mid] == target){
            return true;
        } else if( mat[mid] > target ){
            e = mid-1;
        } else if( mat[mid] < target ){
            s = mid+1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int> >& matrix, int target){


    int s = 0;
    int e = matrix.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        int inner_mat_size = matrix[mid].size()-1;
        if( matrix[mid][0] >= target && matrix[mid][inner_mat_size] <= target ){
            return searchInMatix(matrix[mid], target);
        } else if( matrix[mid][0] > target ){
            e = mid-1;   
        } else if( matrix[mid][inner_mat_size] < target ){
            s = mid+1;
        }
    }

    return false;
}

int main(){

    int m,n; //m = rows, n = cols
    cin>>m>>n;

    vector<vector<int> > nums;

    for(int i=0;i<m;i++){
        vector<int> vec;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        nums.push_back(vec);
    }
    int target;
    cin>>target;
    cout<<target<<endl;
    cout<<searchMatrix(nums,target)<<endl;
    //print(nums);
    return 0;
}

/*


3 4
1 3 5 7
10 11 16 20
23 30 34 60
3

1
3 

 1  3  5  7
10 11 16 20
23 30 34 60

11 12 13 14
15 16 17 18
19 20 21 22
23 24 25 26
27 28 29 30




*/