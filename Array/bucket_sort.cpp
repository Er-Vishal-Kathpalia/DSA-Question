#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Student{
	public:
		string name;
		int marks;
};

void bucket_sort(Student s[], int n){

	//assuming marks are in range 0-100
	vector<Student> v[101];

	for(int i=0;i<n;i++){
		int m = s[i].marks;
		v[m].push_back(s[i]);
	}



	for(int i=100;i>=0;i--){
		for(vector<Student>::iterator it=v[i].begin();it!=v[i].end();it++){
			cout<<(*it).marks<<"  "<<(*it).name<<endl;
		}
	}

}


int main(){

	Student s[10000];

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>s[i].marks>>s[i].name;
	}

	bucket_sort(s,n);

	return 0;
}

/*

Sort the student array with students have high marks should come at top and low marks at bottom.
10 A
100 B
26 C
11 D

v[10] = s[i]
v[100]
v[26]
v[11]


*/




