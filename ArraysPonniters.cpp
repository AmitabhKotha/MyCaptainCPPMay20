#include<iostream>
using namespace std;

int main(){
	int arr[20];
	int n;
	int *p;
	cout<<"How many numbers you want to enter ? (Maximum is 20 numbers)"<<endl;
	cin>>n;
	cout<<"Please enter the numbers:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	p=arr;
	cout<<"The numbers you've entered are:"<<endl;
	for(int i=0;i<n;i++){
		cout<<*(p+i)<<endl;
	}
	return 0;
}
