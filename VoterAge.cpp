#include<iostream>
#include<string>
using namespace std;
int main(){
	int age;
	string str;
	
	cout<<"Enter your age: ";
	cin>>age;
	
	if(age>=80){
		str="Wow!!,You are really old. But you can still vote" ;
	}
	else{
		str = (age>=18)?"You are eligible to vote.":"You are not eligible to vote.So grow up!!";
	}
	
	cout<<str;
	return 0;
}
