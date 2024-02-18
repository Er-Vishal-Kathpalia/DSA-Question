#include <iostream>
using namespace std;

int reverse(int x) {
    long int rev_num = 0;
    //convert the x in positive
    int pos_x = abs(x);
    while(pos_x>0){
        rev_num = (rev_num*10)+(pos_x%10);
        if( rev_num > INT_MAX ){
            return 0;
        }
        pos_x = pos_x/10;
    }
    return rev_num;
}


bool isPalindrome(int x){

	int rev = reverse(x);
	if(rev == x){
		return true;
	}
	return false;
}

int main(){

	int var;
	cin>>var;

	if(isPalindrome(var)){
		cout<<"TRUE"<<endl;
	}
	else{
		cout<<"FALSE"<<endl;
	}

	return 0;
}