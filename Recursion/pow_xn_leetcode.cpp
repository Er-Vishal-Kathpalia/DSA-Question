#include <bits/stdc++.h>
using namespace std;

// double myPow(double x, int n){
    
//     if( n == 0 ){
//         return 1;
//     }
//     if( n == 1 ){
//         return x;
//     }

//     if( n < 0 ){
//         n = n / -1;
//         return 1/(x*myPow(x,n-1));
//     } else{
//         return x*myPow(x,n-1);
//     }
// }


double pow(double x, long long int n){

    if( n == 0 ){
        return 1;
    }

    double small_pow = pow(x, n/2);
    small_pow *= small_pow;

    if(n&1){
        return small_pow = small_pow*x;
    }

    return small_pow;
}


//Fast power recursion
double myPow(double x, int n){

    if( n == 0 || n >= INT_MAX || n <= INT_MIN ){
        return 1;
    }

    if( n < 0 ){
        long long int nn = (long) n/-1;
        return 1/pow(x, nn);
    }

    return pow(x,n);
}

int main(){

    double x;
    int n;

    cin>>x;
    cin>>n;

    cout<<myPow(x,n)<<endl; 

    return 0;
}


/*
2^10 = 2*2*2*2....


*/

