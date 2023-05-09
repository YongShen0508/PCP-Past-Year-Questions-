#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//May 2022 Q5
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

