#include<iostream>
#include<string>
using namespace std;

class TimeClass{
	private : 
		int sec,min,hrs;
	public:
		int totalSeconds(){
			return this->sec+(this->min*60)+(this->hrs*3600);
		}
		void setTime(int s,int m,int h){
			this->sec=s;
			this->min=m;
			this->hrs=h;
		}
};

int main(){
	TimeClass t;
	int hrs,min,sec;
	
	cout<<"Enter the time : "<<endl;
	cout<<"Hours : ";cin>>hrs;
	cout<<"Minutes : ";cin>>min;
	cout<<"Seconds : ";cin>>sec;
	
	t.setTime(sec,min,hrs);
	cout<<"Total Time in Seconds : "<<t.totalSeconds();
		
	return 0;
}
