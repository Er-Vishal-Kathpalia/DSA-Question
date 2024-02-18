#include<iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Student{
public:
	string first_name;
	string last_name;
	string rollNo;

	Student(string fname, string lname,string rNo){
		first_name = fname;
		last_name = lname;
		rollNo = rNo;
	}


	bool operator==(const Student &s) const {
		return rollNo == s.rollNo;
	}

};

class HashFn{
public:
	size_t operator()(const Student &s) const {
		return s.first_name.length() + s.last_name.length();
	}

};


int main(){

	Student s1("Ram","Kumar","10");
	Student s2("Sham","Kumar","20");
	Student s3("Puneet","Kathpalia","30");
	Student s4("Ram","Kumar","40");

	unordered_map<Student,int,HashFn> student_map;

	student_map[s1] = 84;	
	student_map[s2] = 22;
	student_map[s3] = 97;
	student_map[s4] = 51;

	for(auto it:student_map){
		cout<<it.first.first_name<<" "<<it.first.last_name<<" :: Marks: "<<it.second<<endl;
	}
	return 0;
}