#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int b[n];
	int c[n+n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int z=1;
	int i=1;
	int j=1;
	while(i<=n && j<=n){
		if(a[i]<=b[j]){
			c[z]=a[i];
			i++;
			z++;
		}
		else{
			c[z]=b[j];
			j++;
			z++;
		}
	}
	while(i<=n){
		c[z]=a[i];
		z++;
		i++;
	}
	while(j<=n){
		c[z]=b[j];
		j++;
		z++;
	}
	//for(int i=1;i<=2*n;i++){
	//	cout<<c[i]<<", ";
	//}
	//cout<<endl;
	int A=1;
	int d=2*n;
	while(A<n*2 && d>0){
		if(c[A]<=c[d]){
			A++;
			d--;
		}
		else{
			A = A;
			d = d;
			break;
		}
	}
	int mid = (c[A]+c[d])/2;
	cout<<mid<<endl;;
	return 0;
}