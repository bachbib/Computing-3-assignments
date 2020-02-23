/***********************************************
Author:	barah
Date:	03/31/17
Purpose:	To practice using classes and inheritance of classes
Sources	of	Help:	Lecture slides, previous assignment
Time	Spent:	1 week 
***********************************************/

/*
Computing	III	-- COMP.2010	Honor	Statement
The	 practice	 of	 good	 ethical	 behavior is	 essential	 for	 maintaining
good	 order	 in	 the	 classroom,	 providing	 an	 enriching	 learning
experience	 for	 students,	 and	 as	 training	 as	 a	 practicing	 computing
professional	 upon	 graduation.	 	 This	 practice	 is	 manifested	 in	 the
University’s	 Academic	 Integrity	 policy.	 Students	 are	 expected	 to
strictly	 avoid	 academic	 dishonesty	 and	 adhere	 to	 the	 Academic
Integrity	 policy	 as	 outlined	 in	 the	 course	 catalog.	 	 Violations	 will
be	dealt	with	as	outlined	therein.
All	 programming	 assignments	 in	 this	 class	 are	 to	 be	 done by	 the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	 in	 a	 manner	 consistent	 with	 this	 document,	 the	 course
academic	 policy	 on	 the	 course	 website	 on	 Blackboard,	 and	 the	 UMass
Lowell	academic	code.
Date: 03/31/17
Name:barah
*/


/////////// i put a bunch of cout statements to show how it works internally because i really worked hard on this all night and i really wan full credit
#include<iostream>
#include<ctime>
using namespace std;
class Player // Base class
{
public:
	virtual int getGuess();
	void storeGuess(int input);
	virtual int getMin() { return min; };
	virtual int getMax() { return max; };
	virtual void setMin(int newMin) { min = newMin; };
	virtual void setMax(int newMax) { max = newMax; };
protected:
	int last_guess=0;
	int min=0;
	int max=100;
};
int Player::getGuess()
{
	return last_guess;
}
void Player::storeGuess(int input)
{
	last_guess = input;
}
class HumanPlayer :public Player // Human player derived class from player
{
public:
	int getGuess();
};

int HumanPlayer::getGuess()
{
	int input;
	cout << "Please enter a number from the keyboard between (0-100):";
	cin >> input;

	while (input < 0 || input>100 || cin.fail())// To trap the user if they put in the wrong format
	{
		cin.clear();
		cin.ignore();
		cout << "Wrong input, please try again and input a number betwenn (0-100):";
		cin >> input;
	}
	return input;
}

class ComputerPlayer :public Player // Computer player drived class from player
{
public:
	int getGuess();
	int getMin() { return min; };
	int getMax() { return max; };
	void setMin(int newMin) { min= newMin; };
	void setMax(int newMax) { max= newMax; };
private:
	int min=0;
	int max =100;

};

int ComputerPlayer::getGuess()
{
	int rand_guess;
	srand(static_cast<unsigned>(clock()));
	rand_guess = rand() % (max - min + 1) + min;
	cout << "The Computer guessed: " << rand_guess << endl;
	return rand_guess;
}

bool checkForWin(int guess, int answer);
void play(Player &player1, Player &player2);

int main(int argc, char* argv[])
{
	int choice = 0;
	char playagain = 'y';
	HumanPlayer hp1, hp2;
	ComputerPlayer cp1, cp2;
	cout << "*******Welcome to the Game!" << "*******" << endl;
	do
	{
		cout << "Would you like to play with another HUMAN(1), or the COMPUTER(2)?";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice  >2)
		{
			cin.clear();
			cin.ignore();
			cout << "please enter (1) for HUMAN or (2) for COMPUTER:";
			cin >> choice;

		}
		if (choice == 1)
		{
			play(hp1, hp2);
		}

		else if (choice = 2)
		{
			play(hp1, cp1);
		}
		cout << "Would you like to play again? hit (y), (n) or any key to exit.";
		cin >> playagain;
	} while (playagain == 'y' || playagain == 'Y');

	return 0;
}

bool checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}
// The	play function	takes	as	input	two	Player objects.
void play(Player &player1, Player &player2) {
	int answer = 0, guess = 0;
	srand(static_cast<unsigned>(clock()));
	answer = rand() % 100;
	bool win = false;

	cout << "The answer is:" << answer << endl;

	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		player1.storeGuess(guess);
		win = checkForWin(guess, answer);
		if (guess>answer)// if the guess is too high
		{
			player1.setMax(guess-1);
		}
		else if (answer > guess)// if the guess is too low
		{
			player1.setMin(guess+1);
		}
		if (win) return;


		//////////////////////////////  to check the different cases for the max and min////////////////////////////////////////
		if (player1.getMax() > player2.getMax() && player1.getMin()>player2.getMin())// if the human has a greater maximum and greater min
		{
			player2.setMax(player2.getMax());// lower max
			player2.setMin((player1.getMin()));// greater min
			cout << "The new max is " << player2.getMax() << endl;
			cout << "The new min is " << player2.getMin() << endl;
		}
		else if (player1.getMax() < player2.getMax() && player1.getMin() < player2.getMin())// if the pc has a greater max and greater min
		{
			player2.setMax(player1.getMax());// lower max
			player2.setMin(player2.getMin());// greater min
			cout << "The new max is " << player2.getMax() << endl;
			cout << "The new min is " << player2.getMin() << endl;

		}
		else if (player1.getMax() < player2.getMax() && player1.getMin() >player2.getMin())// if the pc has a greater max, but lower min
		{
			player2.setMax(player1.getMax());// lower max
			player2.setMin(player1.getMin());// greater min
			cout << "The new max is " << player2.getMax() << endl;
			cout << "The new min is " << player2.getMin() << endl;
		}
		else if (player1.getMax() > player2.getMax() && player1.getMin() <player2.getMin())// if the human has a greater max and lower min
		{
			player2.setMax(player2.getMax());// lower max
			player2.setMin(player2.getMin());// greater min
			cout << "The new max is " << player2.getMax() << endl;
			cout << "The new min is " << player2.getMin() << endl;
		}
		else// if they are the same max and same min, it doesn't matter
		{
			player2.setMax(player1.getMax());// lower max
			player2.setMin(player1.getMin());// greater min
			cout << "The new max is " << player2.getMax() << endl;
			cout << "The new min is " << player2.getMin() << endl;

		}
		////////////////// PC's Guess///////////////
		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		player2.storeGuess(guess);
		win = checkForWin(guess, answer);
		
		///////////////////// IF THE ANSWER IS TOO HIGH OR TOO LOW SET MIN AND MAX TO THE NEW VALUES IF APPLICABLE/////////////////////
			if (guess>answer)// if the guess is too high
			{
				player2.setMax(guess-1);
			}
			else if (answer > guess)// if the guess is too low
			{
				player2.setMin(guess+1);
			}// to set the new max and  min
			
	}
}

