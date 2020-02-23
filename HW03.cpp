/***********************************************
Author: Barah Chbib
Date: 02/01/17
Purpose: To practice writing public and private classes
Sources of Help:
previous knolwledge in c, lecture slides, cplusplus.com, Tutoring
Time Spent: 3 hours
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
Date: 02/01/17
Name: Barah Chbib
*/



#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
	// Public members
	// parameter constructor 
	Point(double x= 0,double y= 0);
	void move(double input_x,double input_y);
	void rotate90();
	//Mutator
	void setXY(double X,double Y);
	//Accessors
	double getX() { return x;}
	double getY() { return y;}

private:
	//Private members
	double x, y;

};
// To change x and y to whatever user inputs
Point::Point(double ChangeX, double ChangeY)
{
	x = ChangeX;
	y = ChangeY;
}
//To set the X and Y coordinates to the new specified location
void Point::setXY(double X,double Y)
{
	x = X;
	y = Y;
}
// To move to the point specified
void Point::move(double changeX,double changeY)
{
	x += changeX;
	y += changeY;
}
// To rotate 90 degrees clockwise
void Point::rotate90()
{
	double temp;
	temp = x;
	x = y;
	y =-1 * temp;
}

int main(int argc, char* argv[])
{
	
	Point one,two;// Declaring two points with original coordinates of (0,0)
	double Xvalue, Yvalue;// Declaring x and y for coordinates
	
	// To set the first point to (1,2)
	one.setXY(1,2);
	cout << "The current location of one after setting 1st time is (" << one.getX() << "," << one.getY() <<")"<< endl;
	// To rotate 90 degrees
	one.rotate90();
	cout << "The current location of one after 1st rotation is (" << one.getX() << "," << one.getY() << ")" << endl;

	one.rotate90();
	cout << "The current location of one after 2nd rotation is (" << one.getX() << "," << one.getY() << ")" << endl;

	one.rotate90();
		cout << "The current location of one after 3rd rotation is (" << one.getX() << "," << one.getY() << ")" << endl;

	one.rotate90();
	cout << "The current location of one after 4th rotation is (" << one.getX() << "," << one.getY() << ")" << endl;

	// To set the first point to (3,4)
	one.setXY(3,4);
	cout << "The current location of one after setting 2nd time is (" << one.getX() << "," << one.getY() << ")" << endl;

	// To move the first point by (1,1)
	one.move(1,1);
	cout << "The current location of one after move is (" << one.getX() << "," << one.getY() << ")" << endl;

	// To set the second point to (5,-4)
	two.setXY(5,-4);
	cout << "The current location of two is (" << two.getX() << "," << two.getY() << ")" << endl;

	// To move the second point by (-5,4).
	two.move(-10,8);
	cout << "The current location of two after moving first time is (" << two.getX() << "," << two.getY() << ")" << endl;

	// To move the point back to the origin (0,0) 
	two.move(5,-4);
	cout << "The current location of two after move is (" << two.getX() << "," << two.getY() << ")" << endl;


	return 0;
}