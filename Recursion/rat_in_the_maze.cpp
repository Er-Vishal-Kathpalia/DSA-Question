#include<bits/stdc++.h>
using namespace std;

/*
Problem
Rat in a Maze
Given a MxN matrix, with some cells as blocked you have to-
1) Find path from src to dest 
2) Count the no of paths from src
3) Print all possible paths
Given the rat can move only forward and down.
*/


bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n){

	if(i==m && j==n){
		soln[m][n]=1;
		//Print the path
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}

	//Rat Should be inside grid
	if(i>m || j>n){
		return false;
	}

	if(maze[i][j] == 'X'){
		return false;
	}

	//Assume soln exist through current cell
	soln[i][j] = 1;

	//Recursive case
	bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n);
	bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);

	//Backtracking
	soln[i][j] = 0;

	if(rightSuccess || downSuccess){
		return true;
	}

	return false;
}


int main(){

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int soln[10][10] = {0};

	int m=4,n=4;

	bool ans = ratInMaze(maze,soln,0,0,m-1,n-1);

	if(ans == 0){
		cout<<"Path doesn't exist"<<endl;
	}

	return 0;
}