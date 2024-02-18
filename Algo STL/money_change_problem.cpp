#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


bool compare(int a, int b){
	return a<=b;
}

int main(){
	long long int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int n = sizeof(coins)/sizeof(coins[0]);
	long long int money = 10000;

	// while(money > 0){
	// 	for(long long int j=n-1;j>=0;j--){
	// 		if(coins[j]<=money){
	// 			cout<<coins[j]<<" ";
	// 			money = money - coins[j];
	// 			break;
	// 		}
	// 	}
	// }


	while(money>0){
		auto lb = lower_bound(coins, coins+n, money, compare);
		int coin = coins[lb-coins-1];
		cout<<coin<<endl;
		money = money - coin;
	}
	return 0;
}


/*





*/