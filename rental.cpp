#include <iostream>
#include <string>
using namespace std;

int main()
{
	//initializing variables
	int startingOdometer, endingOdometer, rentalDays, month, baseCharge;
	const double firstCharge = 0.27;
	string name, luxuryCar;
	double charge, nextCharge, lastCharge = 0.19;

	//gather the input
	cout << "Odometer at start: ";
	cin >> startingOdometer;
	cout << "Odometer at end: ";
	cin >> endingOdometer;
	cout << "Rental days: ";
	cin >> rentalDays;
	cin.ignore(10000, '\n');
	cout << "Customer name: ";
	getline(cin, name);
	cout << "Luxury car? (y/n): ";
	getline(cin, luxuryCar);
	cout << "Month (1=Jan, 2=Feb, etc.): ";
	cin >> month;
	cout << "---" << endl;
	
	//format rental charge
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//check that the input is valid
	if (startingOdometer < 0)
		cout << "The starting odometer reading must be nonnegative." << endl;
	else if (endingOdometer < startingOdometer)
		cout << "The final odometer reading must be at least as large as the starting reading." << endl;
	else if (rentalDays <= 0)
		cout << "The number of rental days must be positive." << endl;
	else if (name == "")
		cout << "You must enter a customer name." << endl;
	else if (luxuryCar != "y" && luxuryCar != "n")
		cout << "You must enter y or n." << endl;
	else if (month < 1 || month > 12)
		cout << "The month number must be in the range 1 through 12." << endl;
	else 
	{
		//calculate the rental charge
		int miles = endingOdometer - startingOdometer;
		if (luxuryCar == "y")
			baseCharge = 61;
		else
			baseCharge = 33;
		if (month == 12 || (month >= 1 && month <= 3))//charge rate is $0.27 during winter months and $0.21 during other months
			nextCharge = 0.27;
		else
			nextCharge = 0.21;
		
		if (miles <= 100)//calculate the charge of miles less than or equal to 100, first 100 miles cost $0.27/mile
			charge = baseCharge * rentalDays + firstCharge * miles;
		if (miles > 100 && miles <= 400)//first 100 miles cost $0.27/mile, next 300 miles depend on month
			charge = baseCharge * rentalDays + firstCharge * 100 + (miles-100) * nextCharge;
		if (miles > 400)
			charge = baseCharge * rentalDays + firstCharge * 100 + nextCharge * 300 + lastCharge * (miles - 400);//every mile beyond 400 is $0.19/mile

		cout << "The rental charge for " << name << " is $" << charge << endl;
	}


}