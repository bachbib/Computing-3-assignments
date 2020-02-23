/***********************************************
Author: Barah Chbib
Date: 01/29/17
Purpose: To make a program that converts feet and inches to meters and centimeters

Sources of Help:
previous knolwledge in c, lecture slides, cplusplus.com 
Time Spent: 2 hours
***********************************************/

/*
Computing
III
-­‐-­‐
COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom,
providing an enriching learning experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the University’s Academic Integrity policy.
Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy
as outlined in the course catalog.
Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone.
No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with
this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
Date: 01/29/17
Name: Barah Chbib
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
const int inchToFeet = 12;// values of inches in a foot
const double feetTometers = 0.3048;//values of meters in one foot 
const int cmToMeters = 100;// value of centimeters in a meter
using namespace std;
void Input_feet_and_inches(int &feet, double &inches);
void convert(int feet, double inches, int &meters, double &cm);
void output(int feet, double inches, int meters, double cm);
int main(int argc, char* argv[])
{
	int feet;
	double inches;
	double converted;
	int meters;
	double cm;
	Input_feet_and_inches(feet, inches);
	convert(feet,inches,meters,cm);
	output(feet, inches, meters, cm);

	return 0;
}
void Input_feet_and_inches(int &feet,double &inches)// This function is for the user to input the values the want to convert
{
	cout << "Please enter the nmber of feet:";
	cin >> feet;
	cout << "Please enter the number of inches:";
	cin >> inches;

}

void convert(int feet,double inches,int &meters, double &cm)// This function is to convert from feet and inches to cm and meters
{
	
	double converted;
	converted = feet + (inches/inchToFeet);// feet and inches to feet 
	converted *= feetTometers;// feet to meters
	meters = floor(converted);// using floor as directed
	cm = (converted-meters)*cmToMeters;
	


}
void output(int feet, double inches, int meters, double cm)// This function is to output the final result 
{

	cout << feet << " feet and " << fixed << setprecision(8)<< inches << " inches converts to" << endl;
	cout << meters << " meters and "<<fixed<< setprecision(8) << cm <<" centimers"<<endl;


}


