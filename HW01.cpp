/***********************************************
Author: Barah Chbib
Date: 01/23/17
Purpose:To apply what was learned in computing 1 and 2 in order to make a program in c++ that allows the user to play a guessing game with numbers

Sources of Help:
previous knolwledge in c, lecture slides
http://mathbits.com/MathBits/CompSci/Pointers/Functions.htm to see an example of how pointers are used in c++

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
Date: 01/23/17
Name: Barah Chbib
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void Input_min_max(int &min,int &max);
void guess(int &min, int &max,int random_number);
int main()
{
	int min=0;
	int max = 0;
	int random_number;
	char choice = 'y';
	srand(static_cast<unsigned>(clock()));
	cout << "*******Welcome to the Game!" << "*******" << endl;
	cout << "First, let's set up the game." << endl;
	do {
		Input_min_max(min, max);
		random_number = rand() % (max - min + 1) + min;
		guess(min, max, random_number);
		min = 0;
		cout <<"Would you like to play again (y or n)?" ;
		cin >> choice;
	} while (choice=='y');
	return 0;
}

void Input_min_max(int &min,int &max)// This function is to store input of min and max
{
	while (min <= 0)// To exclude the numbers less than zero, as well as zero
	{
		cout << "Please enter the minimum number,a positive integer:";
		cin >> min;
	}
	cout << "Please enter the maximum number, which is greater than the minimum and less than 1000: ";
	cin >> max;
	while (max <= min  || max >1000)// To exclude the numbers less than or equal to the min, and over 1000
	{
		cout << "I'm sorry, please enter the maximum number, which is greater than the minimum and less than 1000: ";
		cin >> max;
	}
}
// This function is to allow the user to enter the number of guesses that they would like to guess 
//it also checks if the entered guess was too low or too high
// also when the user is out of guesses it either prints out that they guessed right or they are our of guesses
void guess(int &min, int &max,int random_number)
{
	int guess, numb_of_guesses=0;
	int counter;
	char done = 'n';
	while (numb_of_guesses >= 10 || numb_of_guesses < 1)
	{
		cout << "Please enter the number of guesses allowed (less than 10):";
		cin >> numb_of_guesses;
	}
	cout << "Now, I have a number between " << min << " and " << max << ". Can you guess my number?";
	cin >> guess;

	for (counter = 1; counter < numb_of_guesses;counter++)
	{
		if (guess > random_number)
		{
			cout << "Too high!Try again.";
			cin >> guess;
			done = 'n';
		}
		else if(guess < random_number)
		{
			cout << "Too low!";
			cin >> guess;
			done = 'n';
		}
		else
		{
			cout <<"Excellent! you guessed the number!"<<endl;
			counter = guess;// setting the counter to the random number in order to exit the loop
			done = 'y';
		}
	}
	if (done!='y')// so it won't print statement unless there wasn't any guess that was right
	cout << "Sorry, you can't guess any more. The number is:" << random_number << endl;
}