#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<cmath>
#include <cctype>
using namespace std;


//September 2022 Q3(b)
/*
void readInputToArray(string, int storeFigure[], int&);
int main(){
	string filename;
	int storeFigure[100];
	int totalFigure;
	readInputToArray(filename, storeFigure, totalFigure);
	cout << totalFigure << endl;
}
void readInputToArray(string filename, int storeFigure[], int& totalFigure){
	ifstream infile;
	infile.open(filename);
	if (infile.fail())
		cout << "unable to open file";
	else{
		int nointeger = 0;
		while (!infile.eof()){
			infile >> storeFigure[nointeger];
			totalFigure += storeFigure[nointeger];
			nointeger++;
		}
	}
}
*/

//September 2022 Q4
/*
int item;//store fruit data
struct fruitData
{
	string fruitName;
	float price;
}fruits[20];
struct invoiceData {
	int NoOfFruit_ordered;
	float pound_ordered, totalFruitPrice;
	fruitData fruit[20];
}customers[100];
void readInput(fruitData);
void fruitPurchase(invoiceData);
int main()
{
	readInput(fruits);
	cout << "Welcome to fruit Market" << endl;

	for (int i = 0; i < item; i++)
	{
		cout << fruits[i].fruitName << endl;
		cout <<"Price ="<< fruits[i].price <<" per pound"<< endl;
	}
	fruitPurchase(customers);
}
void readInput(fruitData fruits[20])
{
	item = 0;
	ifstream infile;
	infile.open("fruit.txt");
	if (infile.fail())
		cout << "unable to open the file";
	else
	{
		while(!infile.eof())
		{
			getline(infile, fruits[item].fruitName);
			infile >> fruits[item].price;
			item++;
		}
	}
	infile.close();
}
void fruitPurchase(invoiceData customers[])
{
	ofstream outfile;
	outfile.open("CustomerHistory.txt");
	string fruit;
	int index=999,record=0;
	float pounds;
	char otherfruit, purchase;
	bool exit=true;
	do {
		outfile << "customer ID" << record + 1 << endl;
		do {
			cout << "Enter the fruit name that customer would like to purchase: ";
			getline(cin, fruit);
			for (int i = 0; i < item; i++){
				if (fruit == fruits[item].fruitName)
					index = i;
			}
			if (index == 999)
				cout << "invalid input detected" << endl;
			else{
				cout << "how many pounds?";
				cin >> pounds;
				cout << "Do you wish to add other fruit?";
				cin >> otherfruit;
				customers[record].NoOfFruit_ordered++;
				customers[record].pound_ordered = pounds;
				cout << "Fruit type :" << fruit;
				cout << "No. of pound =" <<pounds;
				customers[record].totalFruitPrice += fruits[index].price * pounds;
				customers[record].fruit[customers[record].NoOfFruit_ordered-1].fruitName = fruits[index].fruitName;
			}
		} while (toupper(otherfruit)=='Y');
		cout << "Next Purchase? ";
		cin >> purchase;
		outfile << "Customer " << record<<"have ordered "<< customers[record].NoOfFruit_ordered<<"with total price of RM "<< customers[record].totalFruitPrice;
		if(toupper(purchase)=='Y')
			record++;
	} while (toupper(purchase)=='Y');
}
*/



//September 2022 Q5
/*
struct PUBG
{
	string username;
	int total;
	float hour;
	bool status;
};
void readUser(PUBG PUBGAcc[], int& totalPlayer)
{
	cout << "Create Users Account of PUBG";
	getline(cin, PUBGAcc[totalPlayer].username);
	cout << "Total Games Player: ";
	cin >> PUBGAcc[totalPlayer].total;
	cout << "Hour's Games Played: ";
	cin >> PUBGAcc[totalPlayer].hour;
	cout << "current online status: ";
	cin >> PUBGAcc[totalPlayer].status;
}
void totalGamesPlayerByAllUsers(PUBG PUBGAcc[],int& totalPlayer)
{
	float total_hours = 0;
	for (int i = 0; i < totalPlayer; i++)
	{
		total_hours += PUBGAcc[i].hour;
	}
	cout << "Total games played by users is " << total_hours << endl;
}
void CheckCurrentOnlineStatus(PUBG PUBGAcc[], int& totalPlayer)
{
	int online = 0;
	cout << "current online player";
	for (int i = 0; i < totalPlayer; i++)
	{
		if (PUBGAcc[totalPlayer].status)
			cout << PUBGAcc[totalPlayer].username;
	}
	cout << "Total of current online player is " << online;
}
int main()
{
	PUBG PUBGAcc[100];
	int totalPlayer = 0;
	int answer = 1;
	while (answer == 1)
	{
		readUser(PUBGAcc, totalPlayer);
		cout << "Continue? 1 - Yes, 2 - No: ";
		cin >> answer;
		cin. ignore();
	}

	cout << "Total games played by users is ";
	cout<<totalGamesPlayerByAllUsers(PUBGAcc, totalPlayer)<< ". " << endl;
		
	CheckCurrentOnlineStatus(PUBGAcc, totalPlayer);
}
*/

//May 2022 Q5
/*
struct bookStore
{
	string title, author;
	int year, best_seller;
	double price;
};
void readBook(bookStore book[], int& noBook)
{
	ifstream infile;
	infile.open("book.txt");
	if (infile.fail())
		cout << "unable to open the file" << endl;
	else
	{
		while (!infile.eof())
		{
			getline(infile,book[noBook].title);
			getline(infile,book[noBook].author);
			infile>>book[noBook].year>>book[noBook].best_seller;
			infile>>book[noBook].price;
			noBook++;
		}
	}
}
void displayBook(bookStore book)
{
	cout <<"Title: "<< book.title;
	cout <<"Author: "<< book.author;
	cout <<"Year of publication: "<< book.year;
	cout <<"Rank: "<< book.best_seller;
	cout <<"Price: "<< book.price;
}
void bestSellerRank(bookStore book[], int noBook)
{
	int highest = 0;
	for (int i = 1; i < noBook; i++)
	{
		if (book[highest].best_seller < book[i].best_seller)
			highest = i;
	}
	cout << "The best seller in the list is" << endl;
	cout << "Title: " << book[highest].title << endl;
	cout << "Author: " << book[highest].author<<endl;
	cout << "Year of publication: " << book[highest].year<<endl;
	cout << "Rank: " << book[highest].best_seller<<endl;
	cout << "Price: " << book[highest].price;
}
void selectBook(bookStore book[], int noBook)
{
	int start, end,index=0;
	cout << "Please key in the range of year"<<endl;
	cout << "Start: ";
	cin >> start; 
	cout << "Start: ";
	cin >> end;
	for (int i = 0; i < noBook; i++)
	{
		if (start<book[i].year && end>book[i].year)
		{
			cout << "The best seller in the list is" << endl;
			cout << "Title: " << book[i].title<<endl;
			cout << "Author: " << book[i].author<<endl;
			cout << "Year of publication: " << book[i].year << endl;
			cout << "Rank: " << book[i].best_seller << endl;
			cout << "Price: " << book[i].price << endl;
			index++;
		}
	}
	if (index == 0)
		cout << "Sorry, no book is available" << endl;
}
*/

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
/*
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
*/

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
/*
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
*/
//September 2020 Q1
/*
int main()
{
	//Q1 (a)
	//string address@home   (wrong)  only alphabetical value,numerical value and underscore is allowed
	//bool 1Utar;  (wrong) variable name cannot start with numerical value
	//char break; (correct)
	//double Price Tag;  (wrong)  cannot have a space in between variavle name

	//Q1 (b)
	int x = 165;
	cout<< "165 / 10.0 * 16 / 4 ="<<x / 10.0 * 16 / 4<<endl;
	cout << "165*2.7/4 =" << x * 2.7 / 4<<endl;
	cout << "10*20+165/6 ="<< 10 * 20 + x / 6 <<endl;

	//Q1 (c)
	char name[10];
	strcpy(name,"Jason OOi");
	for (int i = 0; i <= 9; i++)
	{
		cout << name[i];
	}
	cout << endl;

	//Q1 (d)
	float number;
	cout << "Input the floating-point number>>";
	cin >> number;
	cout << "The square root of floating number is " << sqrt(number);
}
*/

//September 2020 Q2
/*
int main()
{
	//skip Q2 (a)
	// Q2 (b)
	char selection;
	int total_quantity = 0;
	double total_price = 0;
	cout << "Soda Vendig Machine" << endl;
	cout << "A. 1 Coca-cola RM2.00" << endl;
	cout << "B. 1 Sprite RM2.10" << endl;
	cout << "C. 1 Root Beer RM1.90" << endl;
	cout << "N. Quit" << endl;
	do {
		int quantity = 0;
		double price = 0;
		cout << "Choose your favourite drinks: ";
		cin >> selection;
		switch (toupper(selection))
		{
		case('A'):
		{
			cout << "Quantity: ";
			cin >> quantity;
			price = 2.00;
			cout << fixed << setprecision(2) << quantity << " coca-cola -> RM" << price * quantity<<endl;
			break;
		}
		case('B'):
		{
			cout << "Quantity: ";
			cin >> quantity;
			price = 2.10;
			cout << fixed << setprecision(2) << quantity << " sprite -> RM" << price * quantity<<endl;
			break;
		}
		case('C'):
		{
			cout << "Quantity: ";
			cin >> quantity;
			price = 1.90;
			cout << fixed << setprecision(2) << quantity << " root beer-> RM" << price * quantity<<endl;
			break;
		}
		case('N'):
		{
			cout << "Thank you!!!" << endl;
			break;
		}
		default:
		{
			cout << "Invalid input!" << endl;
			break;
		}
		}
		total_quantity += quantity;
		total_price += price * quantity;
	} while (!(toupper(selection) == 'N'));
	cout << "Total Quantity: " << total_quantity << endl;
	cout << "Total Price: " << total_price << endl;

	//Q2 (c)
	char character;
	do {
		cout << "Enter a character: ";
		cin >> character;
		cout << character << "ASCII value is" << int(character) << endl;
		if (isalpha(character))
			cout << character << " is an alphabet." << endl;
		else if (isdigit(character))
			cout << character << " is a digit." << endl;
	} while (!(toupper(character) == 'N'));
}
*/

//September 2021 Q3
/*
double average(int,int,int,int,int,int);
int main()
{
	//Q3 (a)
	string name[100], id[100];
	int score[100][6], record = 0;
	double average_score[100];
	ifstream infile;
	infile.open("Student.txt");
	if (infile.fail())
		cout << "unable to open the file" << endl;
	else
	{
		while (!infile.eof())
		{
			getline(infile, name[record]);
			getline(infile, id[record]);
			for (int i = 0; i < 6; i++)
				infile >> score[record][i];
			record++;
		}
	}
	for (int i = 0; i < record; i++)
	{
		double avrg = average(score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], score[i][5]);
		average_score[i] = avrg;
		cout << "Student Name: " << name[i] << endl;
		cout << "Student ID: " << id[i] << endl;
		cout << "Average Score: " << average_score[i] << endl;
	}
}
double average(int s1,int s2,int s3, int s4,int s5,int s6)
{
	double average = (s1 + s2 + s3 + s4 + s5 + s6) / 6;
	return average;
}
*/
//September 2021 Q4


struct Sentences {
	char Line[100];
	int characters;
};
void storeSentences(Sentences sentenceList[], int& totalSentences);
int determineLongestSentence(Sentences sentenceList[], int& totalSentences);
int main()
{
	Sentences sentenceList[5];
	int total = 0,empty;
	storeSentences(sentenceList, total);
	empty = determineLongestSentence(sentenceList, total);
	cout << "Empty spaces of the sentence is " << empty << endl;
}
void storeSentences(Sentences sentenceList[], int& totalSentences)
{
	string sentences;
	int nochar;
	do {
		cout << "key in the sentences " << totalSentences + 1<<" :";
		getline(cin, sentences);
		strcpy(sentenceList[totalSentences].Line, sentences.c_str());
		nochar = sentences.length();
		sentenceList[totalSentences].characters = nochar;
		totalSentences++;
	}while(totalSentences < 5);
}
int determineLongestSentence(Sentences sentenceList[], int& totalSentences)
{
	int largest = 0;
	for (int i = 1; i < totalSentences; i++)
	{
		int index = 0;
		if (sentenceList[i].characters > sentenceList[largest].characters)
			largest = i;
	}
	cout << "The largest value is " << sentenceList[largest].Line << endl;
	int index = 0;
	for (int i = 0; i < totalSentences; i++)
	{
		for (int j = 0; j < sentenceList[i].characters; j++)
		{
			if (isspace(sentenceList[i].Line[j]))
			{
				index++;
			}
		}
	}
	return index;
}