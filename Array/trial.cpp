#include <iostream>
using namespace std;

int reverse(int x) {
	int rev_num = 0;
	//convert the x in positive
	int pos_x = abs(x);
	while(pos_x>0){
		rev_num = (rev_num*10)+(pos_x%10);
		pos_x = pos_x/10;
	}

	if(x < 0){
		//convet the rev_num into negative as well
		rev_num = rev_num/-1;
	} 
	return rev_num;
}

int main(){

	int var;
	cin>>var;

	cout<<reverse(var)<<endl;

	return 0;
}