#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<cmath>
#include <cctype>
using namespace std;
//April 2021 Q1
/*
int main()
{
	//1 (a)
	int a = 100, b = 10, c = 6;
	double d = 5.5, e = 2.5;
	cout << "Welcome to division section" << endl;
	cout << "(i) Division of " << a << "/" << b << "=" << a / b << endl;
	cout << "(ii) Division of " << a << "/" << c << "=" << a / c << endl;
	cout << fixed << setprecision(2);
	cout << "(iii) Division of " << c << "/" << b << "=" << double(c) / b << endl;
	cout << "(iv) Division of " << b << "/" << a << "=" << double(b) / a << endl;

	cout <<"The output of " <<b << "*" << d << "*" << e << "=" << b * d * e << endl;
	cout << "The output of ((" << b << "+" << c << ")>(" << d << " + " << e << ")) = "<<((b + c) > (d + e)) << endl;
	
	//1 (b)
	int num1, num2,decision;
	cout << "Key in two numbers: ";
	cin >> num1 >> num2;
	string matharray[4] = { "1. +","2. -","3. *","4. /" };
	for (int i = 0; i < 4; i++)
	{
		cout << matharray[i] << endl;
	}
	cout << "select operator: ";
	cin >> decision;
	if (decision == 1)
	{
		cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	}
	else if (decision == 2)
	{
		cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	}
	else if (decision == 3)
	{
		cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
	}
	else if (decision == 4)
	{
		if (num2 == 0)
			cout << "invalid option" << endl;
		else
			cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
	}
}
*/

//April 2021 Q2
/*
int main()
{
	//skip 2 (a), 2(b)
	//Q2 (c)  (input validation is not required)
	string cont;
	int selection;
	double weight,price=0;
	do{
	cout << "Pick your delivery region" << endl;
	cout << "1. Peninsular Malaysia " << endl;
	cout << "2. East Malaysia " << endl;
	cin >> selection;
	cout << "Please key in the weight of the parcel in kg : ";
	cin >> weight;
	if (selection == 1){
		if (weight < 1){
			price += 8.5;
		}
		else if (weight <= 2 && weight > 1){
			price += 14;
		}
		else if (weight <= 3 && weight > 2){
			price += 24;
		}
		else {
			price += 24;
			double checking;
			checking = (ceil(weight) - 3)*3;
			price += checking;
		}
	}
	if (selection == 2){
		if (weight < 1){
			price += 12.5;
		}
		else if (weight <= 2 && weight > 1){
			price += 20;
		}
		else if (weight <= 3 && weight > 2){
			price += 32;
		}
		else{
			price += 32;
			double checking;
			checking = (ceil(weight) - 3) * 3;
			price += checking;
		}
	}
	cout << "Do you have add another parcel?";
	cin >> cont;
	for (int i = 0; i < cont.size(); i++)
		cont[i] = toupper(cont[i]);
	}while (cont == "Y");
	cout << fixed << setprecision(2);
	cout << "Total payment : " << price << endl;
}
*/

//April 2021 Q3
/*
bool checkCharacter(string IC);
int convertYearOfBirth(string IC);
void CheckEligibility(string name, int year);
int main()
{
	string name, IC;
	int cont = 1, year;
	do {
		cout << "Name :";
		getline(cin, name);
		cout << "IC No (without hypen) :";
		getline(cin, IC);
		if (checkCharacter(IC))
		{
			year=convertYearOfBirth(IC);
			cout << name << " is " << year << " years old." << endl;
			CheckEligibility(name, year);
		}
		else
		{
			cout << "Please key in the correct IC no! " << endl;
		}
		cout << "Cont (1-yes, 2-no)? ";
		cin >> cont;
		cin. ignore();
	} while (cont == 1);
}
bool checkCharacter(string IC)
{
	int size, number=0;
	size = IC.length();
	for (int i = 0; i < size; i++)
	{
		if (isdigit(IC[i]))
			number++;
	}
	if (size == number)
		return true;
	else
		return false;
}
int convertYearOfBirth(string IC)
{
	string year;
	int yr;
	year = IC.substr(0, 2);//start(position), length
	yr = stoi(year);
	if (yr > 21)
		yr += 1900;
	else if (yr <= 21)
		yr += 2000;
	yr = 2021 - yr;
	return yr;
}
void CheckEligibility(string name, int year)
{
	if (year >= 21)
		cout << name << "is eligible to vote." << endl; 
	else if (year < 21)
		cout << name << "is not eligible to vote." << endl;
}
*/

//April 2021 Q4

struct Address {
	int houseNumber;
	char streetName[100];
	int postcode;
	string city, state;
}address;
struct PaintingService {
	int type;
	char furniture;
	double price;
	Address address;
};
void PaintingInfo(PaintingService PaintingList[]);
void TotalChargedEstimation(PaintingService PaintingList[]);
int main()
{
	PaintingService PaintingList[10];
	PaintingInfo(PaintingList);

	TotalChargedEstimation(PaintingList);
	return 0;
}
void PaintingInfo(PaintingService PaintingList[])
{
	char cont;
	int nohouse = 0;
	string streetName;
	do {
		cout << "Please key in your house type: 1-Flat 2-Apartment 3-Condominium 4-Signle Storey 5-Double Storey"<<endl;
		cin >> PaintingList[nohouse].type;
		cout << "Please key in house number: ";
		cin >> PaintingList[nohouse].address.houseNumber;
		cin.clear();
		cin.ignore();
		cout << "Please key in your street name: ";
		getline(cin, streetName);
		strcpy(PaintingList[nohouse].address.streetName,streetName.c_str());
		cout << "Please key in your postcode: ";
		cin >> PaintingList[nohouse].address.postcode;
		cout << "Please key in your city: ";
		cin >> PaintingList[nohouse].address.city;
		cout << "Please key in your state: ";
		cin >> PaintingList[nohouse].address.state;
		cout << "Is your house full of furniture and needs to be shifted? Y-Yes N-No :";
		cin >> PaintingList[nohouse].furniture;
		cout << "Do you want to key in another painting service info? Y-Yes N-No: ";
		cin >> cont;
		nohouse++;
	} while (toupper(cont) == 'Y');
}
void TotalChargedEstimation(PaintingService PaintingList[])
{
	int number=0;
	double total=0;
	string name[5] = { "Flat","Apartment","Condominium","Single Storey","Double Storey" };
	double price[5] = { 1700,2000,2200,2500,3300 };
	ofstream outfile;
	outfile.open("painting.txt");
	for(int i=0;i<10;i++){
		if (PaintingList[i].type >= 1 && PaintingList[i].type<=5){
			number =PaintingList[i].type-1;
			outfile << name[number] << endl;
			outfile << PaintingList[i].address.houseNumber << ","
				<< PaintingList[i].address.streetName << ","
				<< PaintingList[i].address.postcode << ","
				<< PaintingList[i].address.city << ","
				<< PaintingList[i].address.state << "." << endl;
			outfile << "House with furniture:  " << toupper(PaintingList[i].furniture)<<endl;
			PaintingList[i].price = 0;
			if (toupper(PaintingList[i].furniture) == 'Y')
				PaintingList[i].price += 300;
			PaintingList[i].price += price[number];
			outfile << "Estimated Charged: " << PaintingList[i].price << endl;
			total += PaintingList[i].price;
		}
		else{
			cout << endl;
			break;
		}
	}
	outfile << "Total Estimated charged from painting services is " << total << endl;
}
