// ConsoleApplication12.cpp : Defines the entry point for the console application.
// Jason Diaz

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cctype>

using	namespace	std;

const int SIZE = 7;

/*
SkiCalender class - contains a date and its base snow report
The class consists of accessor functions and a display for both date and base
*/
class SkiDate {
private:
	int date;
	double base;
public:
	SkiDate() {
		date = base = 0;
	}
	int getDate() {
		return date;
	}
	double getBase() {
		return base;
	}
	void setDate(int d) {
		date = d;
	}
	void setBase(double b){
		base = b;
	}
	void display() {
		cout << date << "		" << base << endl;
	}

};


void sort(SkiDate calander[]);
void display(SkiDate calender[], string month, int s, int e);

int main()
{
	SkiDate calender[7]; //seven-element array of the SkiCalender object
	string month;
	int startingDate, endingDate;
	double temp;
	bool valid = false; // used for check

	//user input
	cout << "Enter the name of the month: " << endl;
	cin >> month;
	
	while (!valid) {
		cout << "Enter the starting date of the seven-day period being measured:" << endl;
		cin >> startingDate;
		cout << "Enter the ending date of the seven-day period being measured:" << endl;
		cin >> endingDate;

		//input error checking
		if (endingDate - startingDate == SIZE-1) {
			valid = true;
		}
		else {
			cout << "*!*Dates were invalid*!*" << endl;
		}
	}

		for (int i = 0; i < SIZE; i++) {
			calender[i].setDate(startingDate + i);
			cout << "Enter the number of snow in inches for the " << (startingDate + i) << "th:" << endl;
			cin >> temp;
			calender[i].setBase(temp);
		}

		sort(calender);
		display(calender, month, startingDate, endingDate);
		
	system("pause");
    return 0;
}

/*
sort - sorts the data in ascending order by base depth
implimented a bubble sort
*/
void sort(SkiDate calender[]) {
	bool swapped = true;
	int j = 0;
	SkiDate temp;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < SIZE - j; i++) {
			if (calender[i].getBase() > calender[i+1].getBase()) {
				temp = calender[i];
				calender[i] = calender[i+1];
				calender[i+1]= temp;
				swapped = true;
			}
		}
	}
		return;
}

/*
display - displays the result
*/
void display(SkiDate calender[],string month, int s, int e) {
	cout << "Snow Report " << month << " " << s << "-" << e << endl;
	cout << "Date" << "		" << "Base" << endl;

	for (int i = 0; i < SIZE; i++) {
		calender[i].display();
	}
	return;
}