#include <iostream>
#include <fstream>
#include <string>
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


