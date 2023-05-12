#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<cmath>
#include <cctype>
using namespace std;

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
