// assignment2.3.1.1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime> 
#include "windows.h"

void header();
void footer();
void domesticmenu();
void internationalmenu();
void letter(int);
void codes();
void rates();
void info();
int nextday();
int traddelivery();
int flatrate(int);
void stamp(int,int);
using namespace std;

int codes_[22] = { 250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271 };
string zone[22] = { "Islamabad","Lahore","Karachi","Peshawar","Quetta","Bahawalpur","Gawadar","Multan","Hyderabad","Ziarat","Faislabad","Abbottabad","Sukkur","Swat","Chitral","Mardan","Sibi","Turbat","Rawalpindi","Sialkot","Mirpur","Larkana" };
string zoneint[10] = { "London","Paris","Manchester","NewYork","Miami","Milan","Delhi","Stockholm","Istumbul","copenhagen"};
int codesint[10] = { 272,273,274,275,276,277,278,279,280,281};

int main()
{
	system("cls");
	do
	{
		system("cls");
		header();
		cout<<endl;
		cout <<"Please Select the Destination:\n"
			 <<"------------------------------\n\n";
		cout << "1. Domestic " << endl << "2. International\n\n\n\n\n\n\n\n\n\n\n";
		footer();
		string wel;
		cin >> wel;
		if (wel == "1")
		{domesticmenu(); }
		else if (wel == "2")
			internationalmenu();
		else if (wel == "W" || wel == "w")
		{
			system("cls");
			header();
			cout << endl << endl << endl << endl << endl << "Already on Welcome Screen" << endl;
			cout << "Returning in 3 seconds" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			footer();
			Sleep(3000);
		}
		else if (wel == "E" || wel == "e")
		exit(0);
		else if (wel == "C" || wel == "c")
		{codes(); }
		else if (wel == "R" || wel == "r")
		{rates(); }
		else if (wel == "I" || wel == "i")
		{info(); }
		else
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "Invalid Try Again" << endl;
			cout << "Returning back in 5 seconds" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			Sleep(5000);
		}
	} while (true);
	_getch();
}
inline void header()
{	cout<<"________________________________________________________________________________________________________________________\n";
	cout << "\n\t\t\t\t\tBAHRIA UNIVERSITY ISLAMABAD" << endl;
	cout << "\t\t\t\t\tDEPARTMENT OF COMPUTER SCIENCE" << endl;
	cout << "\t\t\t\t\tPAKISTAN POST" << endl;
//This Code Show current Date
	time_t t = time(0);
	struct tm * now = localtime(&t);
	cout << endl << "\t\t\t\t\t"
		<< now->tm_mday << '-'
		<< (now->tm_mon + 1) << '-'
		<< (now->tm_year + 1900)
		<< endl;
	cout<<"________________________________________________________________________________________________________________________\n";
	return;
}
inline void footer()
{	cout<<"========================================================================================================================\n";
	cout << "GOTO" << endl << "----" << endl;
	cout << "Welcome Screen [w]"
		<< "\t\t City Codes [c]"
		<< "\t\t Rates [r]"
		<< "\t\t Info [i]"
		<< "\t\t Exit [e]"
		<< endl;
	cout<<"========================================================================================================================\n";
	return;
}
void domesticmenu()
{
	do
	{
		system("cls");
		header();
		cout<< "\n\t\t\t\t\tDomestic Menu"<<endl<<endl;
		cout<<"________________________________________________________________________________________________________________________\n\n";
		cout<<"Welcome Dear Customer\n" 
			<<"---------------------\n\n";
		cout << "Please Select from the Following Menu" <<endl;
		cout << "1. Post Card Delivery " << endl;
		cout << "2. Letter Delivery" << endl;
		cout << "3. Large Envolope Delivery" << endl;
		cout << "4. Package Delivery" << endl
			<< "5. Large Package" << endl << endl << endl << endl;
		footer();
		string select;
		cin >> select;
		if (select == "1") { letter(1); break; }
		else if (select == "2") { letter(2); break; }
		else if (select == "3") { letter(3); break; }
		else if (select == "4") { letter(4); break; }
		else if (select == "5") { letter(5); break; }
		else if (select == "W" || select == "w") 
			{main(); break; }
		else if (select == "E" || select == "e")
			exit(0);
		else if (select == "C" || select == "c")
			{codes(); }
		else if (select == "R" || select == "r")rates();
		else if (select == "I" || select == "i") info();
		else
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << "Invalid Option" << endl << "Please Retry" << endl << "Going back in 5 seconds";
			Sleep(5000);
		}

	} while (true);
	return;

}
void internationalmenu()
{
	system("cls");
	header();
		cout<< "\n\t\t\t\t\tInternational Menu"<<endl<<endl;
		cout<<"________________________________________________________________________________________________________________________\n";
	cout << endl << "Flat Charges are applied for All types of International Packages";
	cout << endl << "Please Enter the Destination city code";
	int destination;
	while(true)
	{
		cin>>destination;
	if ((destination >=272) && (destination <= 282))
		break;
	else
	cout<<"Please re-enter Valid Code only\n";
	}
	cout << endl << "Please Enter the Weight\n"
			<<"Please Enter in Grams Only\n";
	int weight;
	cin>> weight;
	int weightmoney= weight * 5 ;
	int total = 3000 + weightmoney;
		cout << "Your Total is \n" 
		<<"weight charges : Rs. "<< weight * 5
		<<"\ndestination charges : Rs.  "<< 3000
		<<"\n\nTotal = Rs. "<< total <<endl;
	footer();
	stamp(destination,total);
	footer();
	_getch();
}
void letter(int Package)
{
	while (true)
	{
		system("cls");
		header();
		if (Package == 1)
		{
			cout << "Welcome to Post Card delivery section" << endl << endl;
		}
		else if (Package == 2)
		{
			cout << "Welcome to letter delivery section" << endl << endl;
		}
		else if (Package == 3)
		{
			cout << "Welcome to large Envolope delivery section" << endl << endl;
		}
		else if (Package == 4)
		{
			cout << "Welcome to Package delivery section" << endl << endl;
		}
		else if (Package == 5)
		{
			cout << "Welcome to large Package delivery section" << endl << endl;
		}
		cout << "Please Select the shipment Method\n";
		cout << "1. Next Day Delivery" << endl;
		cout << "2. Traditional " << endl;
		cout << "3. Flat Rate" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		footer();
		string select;
		cin >> select;
		if (select == "1")
		{
			nextday();
		}
		else if (select == "2") { traddelivery(); }
		else if (select == "3") { int a = Package;  flatrate(0); }
		else if (select == "W" || select == "w") { main(); }
		else if (select == "E" || select == "e")exit(0);
		else if (select == "C" || select == "c")
		{
			codes();
		}
		else if (select == "R" || select == "r")cout;
		else if (select == "I" || select == "i") info();
		else
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << "Invalid Option" << endl << "Please Retry" << endl << "Going back in 5 seconds";
		}
		Sleep(5000);
	}
}
inline void rates()
{
	system("cls");
	header();
	cout << "Rates" << endl
		<<"Please Select one Option\n------------------------\n"
		<<"1. National\n2. International";
		int a;
		while(true)
		{
		cin>>a;
		if (a == 1){
			system("cls");
			header();
		cout<<"\t\t\t\t\t\tNational\n\n";
		cout<< "Different Zones have Different Rates" << endl
		<<"For Cities in Zone 1\n"
		<<"For Next Day Delivery Rs. 200 will be charged\n"
		<<"For Traditional day Delivery Rs. 50 will be charged\n"
		<<"For Flat Rate Rs. 1000 will be charged irespective of destination\n"
		<<"*other charges are charged according to weight\n\n\n"
			<<"For Cities in Zone 2\n"
		<<"For Next Day Delivery Rs. 250 will be charged\n"
		<<"For Traditional day Delivery Rs. 100 will be charged\n"
		<<"For Flat Rate Rs. 1000 will be charged irespective of destination\n\n"
		<<"*other charges are charged according to weight\n\n\n"
			<<"For Cities in Zone 3\n"
		<<"For Next Day Delivery Rs. 300 will be charged\n"
		<<"For Traditional day Delivery Rs. 150 will be charged\n"
		<<"For Flat Rate Rs. 1000 will be charged irespective of destination\n\n"
		<<"*other charges are charged according to weight\n\n\n"
		<<"Press Any Key to Go Back\n";
		getch();
		break;
		}
		else if ( a == 2)
		{
			system("cls");
			header();
			cout<<"\t\t\t\t\t\tInternational\n"
			<<"For International Parcels We Have flat Services Charges\n"
			<<"Rs. 3000 will be charged as Service Charges other charges are charged according to weight\n\n\n" 
			<<"Press Any Key to Go Back\n";
			getch();
			break;
		}
		else
		{
		cout<<"PLease press 1 or 2 Only";
		}
		}
		return;
}
inline void codes()
{
	while(true)
	{
	system("cls");
	header();
	cout << "Please Select from the option below:\n-------------------------------" << endl;
	cout << "1. National\n2. International";
	int a;
	cin >> a;
	if (a == 1) 
	{
		system("cls");
		header();
		cout << "Zone 1\n------" << endl;
		cout << "City Name\t\tCity Code" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << zone[i] << "\t\t\t";
			cout << codes_[i] << endl;
		}
		cout << "\nZone 2\n-----" << endl;
		cout << "City Name\t\tCity Code" << endl << endl;
		for (int i = 6; i < 14; i++)
		{
			cout << zone[i] << "\t\t\t";
			cout << codes_[i] << endl;
		}
		cout << "\nZone 3\n------" << endl;
		cout << "City Name\t\tCity Code" << endl << endl;
		for (int i = 14; i < 22; i++)
		{
			cout << zone[i] << "\t\t\t";
			cout << codes_[i] << endl;
		}
		cout << endl;
		footer();
		cout << "Press Any Key to Go back";
		getch();
		break;
	}
	else if (a == 2)
	{
		system("cls");
		header();
		cout << "City Name\t\tCity Code\n";
		for (int i = 0; i < 10; i++)
		{
			cout << zoneint[i] << "\t\t\t";
			cout << codesint[i] << endl;
		}
		footer();
		cout << endl;
		cout <<"Press Any Key to Go back";
		getch();
		break;
	}
	else
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "Invalid option Please Try Again \n";
		cout << "Going back in 3 Seconds... ";
		Sleep(3000);
	}
	}
	return;
}
inline void info()
{
	while (true)
	{
		system("cls");
		header();
		cout << endl << "\t\t\t\t\t\tThankyou For Choosing Pakistan Post\n" << endl;
		cout << "We offer Three services \n\n";
		cout << "1. Next Day Delivery\n";
		cout << "2. Tradional Delivery\n";
		cout << "3. Flat Rate\n\n";
		cout << "Please Select the apropriate option for further details" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		footer();
		_getch();
		string sel;
		while (true)
		{
			cin >> sel;
			if (sel == "1")
			{
				system("cls");
				header();
				cout << "\nNext day Delivery\n\nThis is our Premium Service,Your Parcels are delivered\nin less than 24 hours without any exception of large Packages.\n\n*Fee is charged According to Parcel size and destination."
					<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				footer();
				cout << "Press Any key to go back";
				_getch();
				break;
			}
			else if (sel == "2")
			{
				system("cls");
				header();
				cout << "\nTradtional Delivery\n\nIn Tradtional delivery your Parcels are delivered in 2-3 days but gives you cheaper option and our same trust."
					<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				footer();
				cout << "Press Any key to go back";
				_getch();
				break;
			}
			else if (sel == "3")
			{
				system("cls");
				header();
				cout << "\nFlat Rate\n\nThis is our Flagship Shipment method,Just like next day Delivery Your parcels are delivered in less than 24 hours\n"
					<< "but a Flat rate is charged for all size of Packages giving you peace of mind and saves you from Paper work."
					<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				footer();
				cout << "Press Any key to go back";
				_getch();
				break;
			}
			else if (sel == "w" || sel == "w")
			{
				main(); break;
			}
			else if (sel == "c" || sel == "C")
			{
				codes(); return;
			}
			else if (sel == "R" || sel == "r")
			{
				rates();
			}
			else if (sel == "E" || sel == "e")
				exit(0);
			else if (sel == "I" || sel == "i")
			{}
			else
			{cout<<"Invalid Option Try Again";}
		}
		return;
	}
}
int nextday()
{
	system("cls");
	header();
	cout << "Next Day Delivery Method" << endl;
	cout << "Please Enter the Destination code";
	static int destination;
	int destmoney=200;
	while (true)
	{
		cin>>destination;
		if		 ((destination >= 250) && (destination <= 255))
		{int destmoney = 200;break; }
		else if  ((destination >= 256) && (destination <= 263))
		{int destmoney = 250;break; }
		else if   ((destination>= 264) && (destination <= 271))
		{int destmoney = 300;break; }
		else
			cout << "Invalid Option\nPlease Try Again\n";
	}
	cout << "Please Enter The Weight of the Package" << endl << "Please Enter in grams only" << endl;
	int weight;
	cin >> weight;
	int total = destmoney + (weight * 2 );
	cout << "Your Total is \n" 
		<<"weight charges : Rs. "<< weight * 2
		<<"\ndestination charges : Rs. "<< destmoney
		<<"\n\nTotal = Rs. "<< total <<endl;
	footer();
	cout << "Press any key to goto Billing section";
	_getch();
	stamp(destination,total);
return 0;
}
int traddelivery()
{
	system("cls");
	header();
	cout << "Traditional Delivery Method" << endl;
	cout << "Please Enter the Destination code";
	int destination;
	int destmoney = 50;
	while (true)
	{
		cin >> destination;
		if		 ((destination >= 250) && (destination <= 255))
		{int destmoney = 50;break; }
		else if  ((destination >= 256) && (destination <= 263))
		{int destmoney = 100;break; }
		else if   ((destination>= 264) && (destination <= 271))
		{int destmoney = 150;break; }
		else
			cout << "Invalid Option\nPlease Try Again\n";
	}
	cout << "Please Enter The Weight of the Package" << endl << "Please Enter in grams only" << endl;
	int weight;
	cin >> weight;
	cout << endl;
	int total;
	total = destmoney + weight;
	cout << "Your Total is \n" 
		<<"weight charges : Rs. "<< weight 
		<<"\ndestination charges : Rs. "<< destmoney
		<<"\n\nTotal = Rs. "<< total <<endl;
	footer();
	cout << "Press any key to goto Billing section\n";
	_getch();
	stamp(destination,total);
	return 0;
}
int flatrate(int a)
{
	system("cls");
	header();
	cout << "Flat Rate Delivery Method" << endl;
	cout << "-------------------------" << endl << endl;
	cout << "Please Enter the Destination code ";
	int destination;
	cout << endl;
	while (true)
	{
		cin >> destination;
		if ((destination >= 250) && (destination <= 271))
		{break; }
		else
			cout << "Invalid Option\nPlease Try Again\n";
	}
	cout << endl<<endl<<endl 
		<< "Please Enter The Weight of the Package" <<endl
		<< "(Enter in grams only)" <<endl<<endl;
	int weight;
	cin >> weight;
	int total;
		if (weight<2000)
			total = 1000;
		else
			total = 2500;
	cout << " FlatRate of Rs. " << total << " is charged on package ";
			if (weight<2000)
				cout <<"Less than 2Kg for any destination:"<<endl<<endl<<endl<<endl;
			else
				cout <<"Greater than 2Kg for any destination"<<endl<<endl<<endl<<endl;
	footer();
	cout << "Press any key to Billing section\n";
	_getch();
	stamp(destination,total);
	
	return total;
}
inline void stamp(int destination, int total)
{	
	system("cls");
	header();
	cout<<"Please Enter Receiver's Name:\n";
		string name;cin>>name;
	cout<<"Please Enter Receiver's Address:\n";
		string add;cin>>add;
	cout<<"Please Enter Receiver's Phone Number:\n";
		int num=0;cin>>num;
	cout<<"Please Enter Your Name:\n";
	string nam;cin>>nam;
	cout<<"Please Enter your Phone no. :\n";
	int numm=0;cin>>numm;
system("cls");
int z;
	if ((destination >= 250) && (destination <= 271))
	{
	for (int i=0;i<22;i++)
	{	
		if (destination == codes_[i])
		{z=i;
		header();
		cout<<"RECEIVER INFORMATION\n"
			<<"--------------------\n\n";
		cout <<"Sending your Parcel to :"<<name<<"\nto city :"<<zone[z]<<"\ncity code is :"<< destination<<endl
			<<"\nAddress: "<<add
			<<"\nPhone number: "<<num;
		cout<<endl<<endl;
		cout<<"SENDER INFORMATION\n"
			<<"------------------\n\n";
		cout<<"Name: " << nam;
		cout<<"\nPhone Number: "<< numm;
			
		cout<<"\nand your Grand total is Rs. "<<total + 50 <<endl;

		break;}
			
	}
	}
	else if ((destination >= 272) && (destination <= 282))
	{
		for (int i=0;i<10;i++)
	{	
		if (destination == codesint[i])
		{z=i;
			header();
		cout<<"\nRECEIVER INFORMATION"
			<<"\n--------------------";
		cout <<"\nSending your Parcel to :  "<<name<<"\n to city :"<<zoneint[z]<<"\ncity code is :"<< destination<<endl
			<<"\nAddress:"<<add
			<<"\nPhone number:"<<num;
		cout<<endl<<endl;
		cout<<"SENDER INFORMATION\n"
			<<"------------------\n";
		cout<<"Name: " << nam;
		cout<<"\nPhone Number: "<< numm;		
		cout<<"\nand your Grand total is Rs. "<<total + 50 <<endl;
		
		break;}
	}
cout<<"________________________________________________________________________________________________________________________";
	}
	cout << "\n|--------------------------|\n"
		<< "|--------------------------|\n"
		<< "|--    Pakistan Post     --|\n"
		<< "|--        O - O         --|\n"
		<< "|--          |           --|\n"
		<< "|--        \\___/         --|\n"
		<< "|--        RS 50         --|\n"
		<< "|--------------------------|\n"
		<< "|--------------------------|\n";
	footer();
char select;
cin>>select;
		if (select == 'W' || select == 'w') 
			{main();}
		else if (select == 'E' || select == 'e')
			exit(0);
		else if (select == 'C' || select == 'c')
			{codes(); }
		else if (select == 'R' || select == 'r')rates();
		else if (select == 'I' || select == 'i') info();
		else main();
}
