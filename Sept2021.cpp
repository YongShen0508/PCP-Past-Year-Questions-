#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<cmath>
#include <cctype>
using namespace std;
//September 2021 Q1
/*
int main()
{
	//Q1(a)
	int x = 10;
	double y = 9.53;
	cout << x << "+" << y << "=" << x + y<<endl;
	cout << x << "-" << y << "=" << x + y<<endl;
	cout << x << "*" << y << "=" << x + int(y)<<endl;
	cout << x << "/" << y << "=" <<fixed<<setprecision(3)<< x + y<<endl;
	//Q1(b)
	int a, b, x,c;
	cout << "input a: ";
	cin >> a;
	cout << "input b: ";
	cin >> b;
	cout << "input x: ";
	cin >> x;
	c = sqrt(a*(pow(x,2)/(b+x)));
	cout << c << endl;
	//Q1(c)
	string name="Tan Leng Lui";
	char vowel[5] = {'A','E','I','O','U'};
	int novowel[5] = { 0,0,0,0,0 },consonant=0,index;
	cout << "**************************"<<endl;
	cout << "*" << setw(10) << "Name : " << name << "  *" << endl;
	for (int i = 0; i < name.length(); i++)
	{
		if (isalpha(name[i]))
		{
			index = 0;
			for (int j = 0; j < 5; j++)
			{
				if (toupper(name[i]) == vowel[j])
				{
					novowel[j]++;
					index++;
				}
			}
			if (index == 0)
				consonant++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "*" << setw(10) << vowel[i] <<" : " << setw(6)<<novowel[i] << "     *" << endl;
	}
	cout << "* " << setw(10) << "consonant : " << setw(6) << consonant << "     *" << endl;
	cout << "**************************" << endl;
}
*/

//September 2021 Q2
/*
int main()
{
	//skip Q2 (a) and (b)
	char cont;
	int option;
	double charge=0;
	int choices, quantity;
	double total_price=0;
	string food[4] = { "Saba Teriyaki","Salmon Avocado Carpaccio","Unagi Kabayaki","Ebi Katsu Curry" };
	double price[4] = { 11.55,15.79,27.45,15.79 };
	string delivery[3] = { "GrabFood","Foodpande","DeliverEat" };
	cout << fixed << setprecision(2);
	do {
		cout << "Food Menu:" << endl;
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << ". " << food[i] << endl;
		}
		cout << "Pich a choices from the list:" << endl;
		cin >> choices;
		if (choices < 1 || choices>4)
			cout << "invalid input" << endl;
		else{
			cout << "Please enter quantity that you want: ";
			cin >> quantity;
			total_price += price[choices - 1] * quantity;
			cout << "You ordered " << quantity << " set(2) of " << food[choices - 1] << ". Price = " << price[choices - 1] * quantity<<endl;
		}
		cout << "Do you want to add other food? (Y-Yes; N-No) : ";
		cin >> cont;
	} while (toupper(cont)=='Y');
	cout << "Please choose delivery service: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ". " << delivery[i] << endl;
	}
	cin >> option;
	if (option == 1)
		charge = 5;
	else if (option == 2)
	{
		if (total_price < 25)
			charge = 5;
	}
	else
		charge = 3 + (total_price * 0.10);
	cout << "Total Food Price: " << total_price<<endl;
	cout << "Delivery Charge: " << charge << endl;
	cout << "Total Price: " << total_price + charge << endl;
}
*/

//September 2021 Q3
/*
//991906,1156486,1177030,1471500,1731231,1944458
//632368,720105,728499,912683,999305,1116994
void KeyInDoses(int oneDose[], int fullVaccine[], int date[], const int);
void highestOneDoseVaccination(int oneDose[], int date[], const int);
void printReport(int fullVaccine[], int oneDOse[], int date[], const int);
int main()
{
	int const sizeOfArray = 6;
	int oneDose[sizeOfArray] = {}, fullVaccine[sizeOfArray] = {};
	int date[sizeOfArray] = { 5,11,15,20,25,30 };
	KeyInDoses(oneDose, fullVaccine, date, sizeOfArray);

}
void KeyInDoses(int oneDose[], int fullVaccine[], int date[], const int sizeOfSrray)
{
	int onedoses, fulldoses;
	for (int i = 0; i < sizeOfSrray; i++)
	{
		cout << "Please key in the accumulated doses." << endl;
		cout << "Date: " << date[i] << " - MAY - 2021" << endl;
		cout << "At least 1 dose : ";
		cin >> onedoses;
		cout << "Fully Vaccinated : ";
		cin >>fulldoses;
		oneDose[i] = onedoses;
		fullVaccine[i] = fulldoses;
	}
}
void highestOneDoseVaccination(int oneDose[], int date[], const int sizeOdArray)
{
	int range,highestdoses,average,record;
	for (int i = 0; i < sizeOdArray-1; i++)
	{
		range = date[i + 1] - date[i];
		if (i == 0)
		{
			highestdoses = i;
			record = range;
		}
		if (oneDose[i] > oneDose[highestdoses])
		{
			highestdoses = i;
			record = range;
		}
	}
	cout << oneDose[highestdoses] << " doses are given from" << date[highestdoses] << " of May 2021 till" << date[highestdoses + 1] << " of May 2021 " << endl;
	cout << "( " << oneDose[highestdoses] / record << " doses in average perm day." << endl;
	cout << "it is the highest number of at least 1 dose given within the period of day" << endl;
}
void printReport(int fullVaccine[], int oneDOse[], int date[], const int sizeOfArray)
{
	int population = 31.9 * 1000000;
	ofstream outfile;
	outfile.open("MAY 2021.txt");
	outfile << "MALAYSIANS WHO RECEIVED COVID-19 VACCINE" << endl;
	outfile << "MAY 2021 REPORT " << endl;
	outfile << "Total Population in Malaysia: 31.9M" << endl << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << "Date: " << date[i] << " - MAY - 2021" << endl;
		cout << fixed << setprecision(1) << "At least 1 dose: " << oneDOse[i] << " " << oneDOse[i] / population * 100 << endl;
		cout << fixed << setprecision(1) << "Fuuly Vaccinated: " << fullVaccine[i] << " " << fullVaccine[i] / population * 100 << endl;
	}
}
*/


//September 2021 Q4

struct Durian {
	string type;
	char taste[50];
	int source;
};

void writeDurianDetails(Durian durian[], int&);
void readDurianDetails(Durian durian[], int&);
int main()
{
	Durian durian[50];
	int nodurian;
	writeDurianDetails(durian, nodurian);
}

void writeDurianDetails(Durian durian[], int& nodurian)
{
	ifstream infile;
	infile.open("durianDetails.txt");
	if (infile.fail())
		cout << "unable to open the file" << endl;
	else
	{
		string descriptions;
		getline(infile, durian[nodurian].type);
		getline(infile, descriptions);
		strcpy(durian[nodurian].taste,descriptions.c_str());
		infile >> durian[nodurian].source;//1 penang 2 pahang 3 johor
		nodurian++;
	}
}
void readDurianDetails(Durian durian[], int& nodurian)
{
	string name;
	string state[3] = { "Penang","Pahang","Johor" };
	int index,type=0;
	cout << "Please enter the source to view the available types of durian: ";
	cin >> name;//input : PeNaNg
	for (int i = 0; i < name.length(); i++)
	{	//output: Penang
		if (i == 0)
			toupper(name[i]);
		else
			tolower(name[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		if (name == state[i])
			index = i;
	}
	for (int i = 0; i < nodurian; i++)
	{
		if (durian[i].source == index + 1)
		{
			cout << "Type [" << type+1 << "]: " << durian[i].type;
			cout << "Taste: " << durian[i].taste;
			type++;
		}
	}
	cout << "There are total " << type << "type(s) of durian(s) available in " << state[index]<<endl;
}
