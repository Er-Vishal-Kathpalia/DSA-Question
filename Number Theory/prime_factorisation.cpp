#include <bits/stdc++.h>
#include <vector>
#include<algorithm>
using namespace std;

//O(n)
void prime_factors_naive_approach(int n){

	vector<pair<int,int> > factors;

	int cnt;
	for(int i=2;i<=n;i++){
		if(n%i==0){
			cnt = 0;
			while(n%i==0){
				cnt++;
				n=n/i;
			}
			factors.push_back(make_pair(i,cnt));
		}
	}
	for(auto factor: factors){
		cout<<factor.first<<" "<<factor.second<<endl;
	}
}

//O(log(n))
void prime_factors(int n){

	vector<pair<int,int> > factors;

	int cnt;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			cnt = 0;
			while(n%i==0){
				cnt++;
				n=n/i;
			}
			factors.push_back(make_pair(i,cnt));
		}
	}

	if(n!=1){
		factors.push_back(make_pair(n,1));
	}

	for(auto factor: factors){
		cout<<factor.first<<" "<<factor.second<<endl;
	}
}


int main(){
	int no;
	cin>>no;

	prime_factors_naive_approach(no);

	return 0;
}