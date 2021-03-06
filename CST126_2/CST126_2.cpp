// CST126_2.cpp : Defines the entry point for the console application.
// Wendell Abigania

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;


//#include "stock.h"

struct stock_picker
{
	string stock_symbol, name;
	double price, earnings;
};

//--------------------------------------------------------------------
bool OpenFile(ifstream& input_file);
//void fill_stock_from_file(Stock &, ifstream &, int & count);
void fill_stock_from_file( ifstream & in_file, int & count);  // temporary starting version.
void tokenizer(char line[], string & symbol, string & name_with_quotes, double & price, double & earnings);



int main(void)
{
	//  STUDENT TASK - define your variables

	// STUDENT TASK - look these up and add a comment to each one to describe what they are doing
	cout.setf(ios::fixed);   // write floating_point values in fixed_point notation (http://www.cplusplus.com/reference/ios/fixed/)
	cout.setf(ios::showpoint); //  decimal point is always written for floating point values inserted into the stream (http://www.cplusplus.com/reference/ios/showpoint/)
	cout.precision(2);  //  floating-point precision determines the maximum number of digits to be written on insertion operations to express floating-point values (http://www.cplusplus.com/reference/ios/ios_base/precision/)

	ifstream stock_file;
	cout << "Welcome to the Stock Picker" << endl << endl;


	if (OpenFile(stock_file))
	{
		while (!stock_file.eof())
		{
			fill_stock_from_file;//(stock[number_stock], stock_file, number_stocks);
		}
		cout << fill_stock_from_file << endl;
		// STUDENT TASK - Loop through your stocks and print them
		cout << endl;
		cout << endl;
		cout << "If you had a 10% appreciation in price the values would be" << endl;
		// STUDENT TASK - Loop through your stocks and 1 - give them a 10% price increase 2 - print them


	}

	return 0;

}

//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// bool    OpenFile(file)
// Input:  file name (retrieved from user);
// Output: file pointer. 
//         Returns true if able to open file and false if 
//           unable to open file
//  Hint:  we've had hands on that did this.
bool OpenFile(ifstream& input_file)
{

	// STUDENT TASK - Prompt the end user for the name of the file like in the sample output.  
	
	char file[20];
	cout << "Please enter the input file name including extension : ";
	cin >> file;

	input_file.open(file);  // use a variabe (character array is fine) to store your file name.  

	if (input_file.fail())
	{
		//  STUDENT TASK:  GIVE THE USER AN ERROR MESSAGE
		cout << "ERROR: Unable to open file : " << file << endl;
		return false;
	}
	else
	{
		cout << "Opened file : " << file << endl;
		return true;
	}

}


//--------------------------------------------------------------------
//void fill_stock_from_file(Stock & s, ifstream & in_file, int & count)
void fill_stock_from_file( ifstream & in_file, int & count)  // temporary starting version.
{
	char line[81];

	//  STUDENT TASK - you'll need some variables.
	string symbol, name;
	double price, earnings;



	in_file.getline(line, 80);
	if (!in_file.eof())
	{
		tokenizer(line, symbol, name, price, earnings);
		cout << endl;
	//  STUDENT TASK -  update your stock here
	}
}

void tokenizer(char line[], string & symbol,string & name_with_quotes,double & price, double & earnings)
{
	

	string token;
	istringstream iss(line);

	std::getline(iss, symbol, ',');
	std::getline(iss, name_with_quotes, ',');
	std::getline(iss, token, ',');
	price = atof(token.c_str());
	std::getline(iss, token, ',');
	earnings = atof(token.c_str());

}
