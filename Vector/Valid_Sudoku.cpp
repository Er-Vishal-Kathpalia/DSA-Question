#include<bits/stdc++.h>
using namespace std;


bool checkRowCol(vector<vector<char> > board,char ch, int i, int j){
    bool ans = true;

    for(int itr=0;itr<9;itr++){
        if( board[itr][j] == ch || board[i][itr] == ch ){
            return false;
        }
    }

    return true;
}

bool checkSubGrid(vector<vector<char> > board,char ch, int i, int j){
    if(i%3==0 && j%3 == 0){
        int arr[9] = {0};
        for(int x=i;x<=i+2;x++){
            for(int y=j;y<=j+2;y++){
                if( board[x][y] != '.' ){
                    int val = board[x][y]-'0';
                    if(arr[val] == 1){
                        return false;
                    }
                    arr[val] = 1;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char> >& board) {

    int n = 9;
    int m = 9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch = board[i][j];
            bool rowColGrid = checkRowCol(board,ch,i,j);
            //bool subGrid = checkSubGrid(board,ch,i,j);
            if(!rowColGrid){
                return false;
            }
        }
    }
    return true;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<char> > board;

    for(int i=0;i<n;i++){
        vector<char> temp;
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            temp.push_back(ch);
        }
        board.push_back(temp);
    }

    cout<<isValidSudoku(board);
    return 0;
}


/*

[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]


4 5 6 7
1 2 3 4







*/