#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<stdio.h>

#define max_seats 32
#define max_buses 20

using namespace std;

string destinations[4]={"Delhi","Mumbai","Kolkata","Hyderabad"};//Only For these destinations 
string password = "HELLO";
class Bus{
	private:
		int seats[max_seats];
		string passengers[max_seats];
	public:
		int count;	
		string bno;
		string destination;
		void setBusDetails(string no,int opt);
		void showAvailable();
		void reserveSeat();
		void cancelSeat();
};

//To Set the details of the bus
void Bus::setBusDetails(string no, int opt){
	bno=no;
	destination=destinations[opt];
	for(int i=0;i<max_seats;i++){
		seats[i]=-1;
	}
	count=0;
}
//Display the available bus seats
void Bus::showAvailable(){
	cout<<"\nReserved seats are marked with 'X'\nUnreserved seats are marked with 'O'."<<endl;
	cout<<"Seats in the Bus number "<<bno<<"(Des:"<<destination<<") are :\n" ;
	for(int i=0;i<max_seats/4;i++){
		if(seats[i]!=-1){
			if(i<10) cout<<"0";
			cout<<(i)<<"[X] "; 
		}
		else{
			if(i<10) cout<<"0";
			cout<<(i)<<"[O] ";
		}
	}
	cout<<endl;
	for(int i=max_seats/4;i<max_seats/2;i++){
		if(seats[i]!=-1){
			if(i<10) cout<<"0";
			cout<<(i)<<"[X] "; 
		}
		else{
			if(i<10) cout<<"0";
			cout<<(i)<<"[O] ";
		}
	}
	cout<<endl;
	cout<<endl;
	for(int i=max_seats/2;i<(3*max_seats/4);i++){
		if(seats[i]!=-1){
			cout<<(i)<<"[X] "; 
		}
		else{
			cout<<(i)<<"[O] ";
		}
	}
	cout<<endl;
	for(int i=(3*max_seats/4);i<max_seats;i++){
		if(seats[i]!=-1){
			cout<<(i)<<"[X] "; 
		}
		else{
			cout<<(i)<<"[O] ";
		}
	}
	cout<<endl;
	
}

//Reserve a particular seat
void Bus::reserveSeat(){
	if(count<max_seats){
		int seat;
		string name;
		showAvailable();
		cout<<"\nEnter the seat to reserve: \t";
		cin>>seat;
		if(seat>max_seats && seat<0){
			cout<<"Please enter a valid seat number.\nSeats are indexed from [0-31].\n";
			reserveSeat();
		} 
		else if(seats[seat]!=-1){
			cout<<"Seat is already reserved.\nPlease select other seat number\n";
			reserveSeat();
		}
		else{
			cout<<"\nEnter the passenger name:\t";
			cin>>name;
			seats[seat]=0;
			passengers[seat]=name;
			cout<<"Successfully reserved the seat to "<<passengers[seat]<<".\n";
			count++;
		}
	}
	else cout<<"\nBus is Full.\n";
	system("pause");
}

//Cancel a ANY SEAT
void Bus::cancelSeat(){
	int seat;
	cout<<"\nEnter the seat to cancel: \t";
	cin>>seat;
	if(seat>max_seats && seat<0){
		cout<<"Please enter a valid seat number.\nSeats are indexed from [0-31].\n";
		cancelSeat();
	} 
	else if(seats[seat]==-1){
		cout<<"Seat is not reserved.\nSo it can't be cancelled.\n";
	}
	else{
		seats[seat]=-1;
		cout<<"Successfully cancelled the seat.\n";
		count--;
	}
	system("pause");
}

//Class that manages all the buses
class BusCompany{
	private : 
		Bus buses[max_buses];
	public :
		int n;
		BusCompany(){
			n=0;
		}
		void busList();
		void addBus();
		void passengerReserve();
		void passengerCancel();
};
//Display the list of buses and their destinations
void BusCompany::busList(){
	if(n==0){
		cout<<"\nNo Buses.\n";
	}
	else{
		cout<<"\nBus Number "<<setw(12)<<" Destination\n";
		for(int i=0;i<n;i++){
			cout<<(i+1)<<"."<<buses[i].bno<<setw(12)<<buses[i].destination<<endl;
		}
	}
	system("pause");
}

//Add a particular bus
void BusCompany::addBus(){
	if(n<=20){
		int opts;
		string number;
		cout<<"\nEnter the bus number : ";
		cin>>number;
		cout<<"\nSelect the bus destination : \n";
		for(int i=0;i<4;i++){
			cout<<(i+1)<<"."<<destinations[i]<<endl;
		}
		cin>>opts;
		if(opts>4 && opts<1){
			cout<<"Select valid option.\n";
		}
		buses[n].setBusDetails(number,opts-1);
		n++;
	}
	else cout<<"\nCannot add more buses.\n";
	system("pause");
}

//Function for Passenger to reserve in a bus 
void BusCompany::passengerReserve(){
	busList();
	int opt;
	cout<<"\nSelect one of the available buses.\n";
	cin>>opt;
	if(opt>n+1 && opt<1){
		cout<<"\nSelect a valid bus number.\n";
		passengerReserve();
	}
	else{
		buses[opt-1].reserveSeat();
	}
	system("pause");
}
//Function for passneger to cancel ticket for a bus
void BusCompany::passengerCancel(){
	busList();
	int opt;
	cout<<"\nSelect one of the available buses.\n";
	cin>>opt;
	if(opt>n+1 && opt<1){
		cout<<"\nSelect a valid bus number.\n";
		passengerCancel();
	}
	else{
		buses[opt-1].cancelSeat();
	}
	system("pause");
}

BusCompany b;//BusCompany global object

//Admin function that only the admin can access
void Admin(){
	string pwd;
	int subopt;
	cout<<"Enter the password: ";
	cin>>pwd;
	if(pwd==password){
		cout<<"Verified Successfully.\n";
		cout<<"1.Add Bus\n"<<"2.Buses List\n";
		cout<<"Enter any option:\t";
		cin>>subopt;
		switch(subopt){
			case 1 : b.addBus();
					 break;
			case 2 : b.busList();
					 break;
			default : cout<<"\nEnter valid option.\n";Admin();
		}
	}
	else{
		cout<<"Verification unsuccessful.\n";
		Admin();
	}
}

//Passenger function to give travellers an option to reserve ticket
void Passenger(){
	int subopt;
	cout<<"\n1.Check Buses\n2.Reserve ticket\n3.Cancel Reservation\n";
	cout<<"\nEnter any option:";
	cin>>subopt;
	switch(subopt){
		case 1 : b.busList();
				 break;
		case 2 : b.passengerReserve();
				 break;
		case 3 : b.passengerCancel();
				 break;
		default : cout<<"\nEnter valid  option.\n";Passenger();
	}
}

int main(){
	int opt;	//Option  for switch
	while(1){
		system("cls");
		cout<<"+++++++++++++MENU+++++++++++++";
		cout<<"\n1.Admin\n2.Traveller\n3.Exit\n";
		cout<<"Enter any option:\t";
		cin>>opt;
		int subopt;
		switch(opt){
			case 1: Admin();
					break;
			case 2:	Passenger();
					break;
			case 3:exit(0);
			default : cout<<"\nEnter valid option.\n";
		}
	}
	return 0;
}
