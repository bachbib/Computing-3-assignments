/***********************************************
Author: Barah Chbib
Date: 02/23/17
Purpose: To write a program that adds up fractions  in fraction form using classes.
Sources of Help:
previous knolwledge in c, lecture slides, cplusplus.com, Tutoring
Time Spent: 5 hours
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
Date: 02/23/17
Name: Barah Chbib
*/


#include <iostream>
#include <string>
using namespace std;
class Rational
{
public:

	//constructors
	Rational();
	Rational(int wholeNumber);
	Rational(int numerator, int denominator);
	
	// << and >> operators
	friend ostream& operator<<(ostream &o, const Rational &r);
	friend istream& operator >> (istream &in, Rational &r);

	// Functions
	void standardize();
	void factorRational();
	//void output(void)const
	// getters
	int getNum()const;
	int getDen()const;
	// setters
	void setNum(int numerator);
	void setDen(int denomenator);
private:
	int n, d;// n is numerator and d is short for denominator
};

//operators overload
bool operator==(const Rational& rhs1,const Rational& rhs2);
const Rational operator+(const Rational& rhs1, const Rational&rhs2) ;
const Rational operator*(const Rational& rhs1,const Rational&rhs2) ;
const Rational operator-(const Rational& rhs1,const Rational& rhs2) ;
const Rational operator/(const Rational& rhs1,const Rational& rhs2) ;

int main()
{
	Rational r1, r2, rCompare1, rCompare2;
	Rational test1;
	Rational test2(3);
	cout << "The default value for the default constructor is:" <<test1<< endl;
	cout << "The value of the whole number 3 in fraction is:" <<test2<< endl;
	cout << "Enter your first fraction in the format numerator/denominator: ";
	cin >> r1;
	rCompare1 = r1;
	r1.factorRational();
	if (rCompare1 == r1)
	{
		cout << "The first fraction can't be simplified further" << endl;
	}
	else
	{
		cout << "The first fraction can be simplified to: " << r1 << endl << endl;
	}
	cout << "Enter your second fraction in the format numerator/denominator: ";
	cin >> r2;
	rCompare2 = r2;

	r2.factorRational();
	if (rCompare2 == r2)
	{
		cout << "The second fraction can't be simplified further" << endl;
	}
	else
	{
		cout << "The second fraction can be simplified to: " << r2 << endl << endl;
	}
	cout << "Operation tests:" << endl;
	cout << r1 << " * " << r2 << " = " << r1*r2 << endl;
	cout << r1 << " + " << r2 << " = " << r1+r2 << endl;
	cout << r1 << " - " << r2 << " = " << r1-r2 << endl;
	cout << r1 << " / " << r2 << " = " << r1/r2<< endl;

	if (r1 == r2)// To test the == overload
	{
		cout << "r1 and r2 are equal" << endl;
	}
	else
	{
		cout << "r1 and r2 aren't equal"<<endl;
	}

	return 0;
}
void Rational::factorRational()// To factor the rational number and make it smaller
{
	const int prime[4] = { 2,3,5,7 };
	bool notFactored = true;
	do
	{
		for (int i = 0; i < 4; i++)
		{
			if ((n % prime[i] == 0) && (d % prime[i] == 0))
			{
					n /= prime[i];
					d /= prime[i];
					break;
			}
			else if (i == 3)
			{
				notFactored = false;

			}
			else
			{
				notFactored = true;
			}
		}
	} while (notFactored);
}
Rational::Rational()
{
	n = 0;
	d = 1;
}
Rational::Rational(int wholeNumber)
{
	n = wholeNumber;
	d = 1;
}
Rational::Rational(int numerator, int denominator) 
{
	n = numerator;
	d = denominator;
	standardize();
}
int Rational:: getNum()const
{
	return n;
}
int Rational:: getDen()const
{
	return d;
}
void Rational:: setNum(int numerator)
{
	n = numerator;
}
void Rational:: setDen(int denomenator)
{
	d = denomenator;
}
void Rational::standardize()// To standrdize the fraction if there's a negative number in the fraction
{
	if (d < 0)
	{
		d = -d;
		n = -n;
	}
	else if (d == 0)
	{
		cout << "The denominator can't be zero!" << endl;
		exit(1);
	}
}

bool operator==(const Rational& rhs1,const Rational& rhs2)
{
	if ((rhs1.getNum() == rhs2.getNum()) && (rhs1.getDen() == rhs2.getDen()))
		return true;
	else
		return false;
}

const Rational operator+(const Rational& rhs1,const Rational&rhs2) 
{
	
	if (rhs1.getDen() == rhs2.getDen())// If denominators are equal
	{
		Rational out(rhs1.getNum() + rhs2.getNum(), rhs1.getDen());
		return out;
	}
	else // If denomenators aren't equal
	{
		Rational set1(rhs2.getNum()*  rhs1.getDen(), rhs2.getDen()* rhs1.getDen());
		Rational set2(rhs1.getNum()*  rhs2.getDen(), rhs1.getDen()*  rhs2.getDen());
		Rational out(set1.getNum() + set2.getNum(), set1.getDen());
	return out;
	}	

}


const Rational operator-(const Rational& rhs1,const Rational& rhs2) 
{
	if (rhs1.getDen() == rhs2.getDen())
	{
		Rational out(rhs1.getNum() - rhs2.getNum(), rhs1.getDen());
		return out;
	}
	else
	{
		Rational set1(rhs1.getNum()*  rhs2.getDen(), rhs2.getDen()* rhs1.getDen());
		Rational set2(rhs2.getNum()*  rhs1.getDen(), rhs1.getDen()*  rhs2.getDen());
		Rational out(set1.getNum() - set2.getNum(), set1.getDen());
		return out;
	}
}

const Rational operator*(const Rational& rhs1,const Rational& rhs2) 
{
	Rational out(rhs1.getNum()* rhs2.getNum(), rhs1.getDen()* rhs2.getDen());
	return out;
}

const Rational operator/(const Rational& rhs1,const Rational&rhs2)
{
	Rational out(rhs1.getNum()*rhs2.getDen(), rhs1.getDen()*rhs2.getNum());
	return out;
}

ostream& operator<<(ostream &o, const Rational &r)
{
	o << r.n << "/" << r.d;
	return o;
}

istream& operator >> (istream &in, Rational &r)
{
	int denom, num;
	char backSlash;
	in >> num;
	in >> backSlash;
	in >> denom;
	if (backSlash != '/')
	{
		cout << "Numerator and denominator should be separated by a  '/' !"<<endl;
		exit(1);
	}
	r.n = num;
	r.d = denom;
	return in;
}