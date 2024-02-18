#include<bits/stdc++.h>
using namespace std;

int R,C;

void print_mat(char mat[][50]){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}

//W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

//ch is the char to be replaced
//colour is the char to be added
void flood_fill(char mat[][50], int i, int j,char ch, char colour){

	//Base case
	if(i<0||j<0||i>=R||j>=C){
		return;
	}

	//Figure Boundry conditions
	if(mat[i][j]!=ch){
		return;
	}

	//Rescursive call
	mat[i][j] = colour;

	for(int k=0;k<4;k++){
		flood_fill(mat,i+dx[k],j+dy[k],ch,colour);
	}

}

int main(){

	cin>>R>>C;

	char input[15][50];

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}

	print_mat(input);
	cout<<endl;
	flood_fill(input,2,15,'.','G');
	flood_fill(input,8,13,'.','R');
	print_mat(input);
	cout<<endl;
	return 0;
}

/*

15 30
..............................
.............#####............
.............#...#............
.....#########...########.....
....###......#####.....###....
...##....................##...
..##......................#...
..##......................##..
..##......................##..
....###................###....
......###............###......
........###........###........
..........##########..........
..............................
...........A.P.P.L.E..........

*/