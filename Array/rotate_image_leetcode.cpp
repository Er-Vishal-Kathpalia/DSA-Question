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

void rotate(vector<vector<int> >& matrix){
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if( i < j ){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    for(int i=0;i<matrix.size();i++){
        vector<int> &mat = matrix[i];
        int x = 0;
        int y = mat.size()-1;
        while(x <= y){
            swap(mat[x], mat[y]);
            x++;
            y--;
        }
    }

    return;
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

    rotate(nums);
    print(nums);
    return 0;
}

/*
1 2 3
4 5 6
7 8 9


00 01 02
10 11 12
20 21 22

1 4 7
2 5 8
3 6 9


7 4 1
8 5 2
9 6 3
*/