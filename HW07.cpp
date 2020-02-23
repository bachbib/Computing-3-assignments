/***********************************************
Author:	Barah
Date: 03/17/17
Purpose: To practice using files, and making a program that finds the number of consecutive pairs in a word 
Sources	of	Help: Lecture slides, Lecture code, tutoring
Time Spent:	2 hours
***********************************************/



/*
Computing	III	-- COMP.2010	Honor	Statement
The	 practice	 of	 good	 ethical	 behavior	 is	 essential	 for	 maintaining
good	 order	 in	 the	 classroom,	 providing	 an	 enriching	 learning
experience	 for	 students,	 and	 as	 training	 as	 a	 practicing	 computing
professional	 upon	 graduation.	 	 This	 practice is	 manifested	 in	 the
University’s	 Academic	 Integrity	 policy.	 Students	 are	 expected	 to
strictly	 avoid	 academic	 dishonesty	 and	 adhere	 to	 the	 Academic
Integrity	 policy	 as	 outlined	 in	 the	 course	 catalog.	 	 Violations	 will
be	dealt	with	as	outlined	therein.
All	 programming	 assignments	 in	 this	 class	 are	 to	 be	 done	 by	 the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	 in	 a	 manner	 consistent with	 this	 document,	 the	 course
academic	 policy	 on	 the	 course	 website	 on	 Blackboard,	 and	 the	 UMass
Lowell	academic	code.
Date: 03/17/17
Name: Barah Chbib
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int consecutive_pairs(const string check);
int main(int argc, char* argv[])
{
	int count=0;
	int mostConsPair = 0;
	string check;
	string mostConsPairString;
	ifstream File;
	File.open("hw07-words.txt");
	if (File.is_open() == 0)// If file doesn't open print out error message
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	else
	{
		while (!File.eof())// To read everything in the file
		{
			File >> check;// To scan in the string
			count = consecutive_pairs(check);// Finding number of consecutive letters

			if (count > mostConsPair)// To find the word with the most number of consecutive pairs 
			{
				mostConsPair = count;
				mostConsPairString = check;
			}
		}
	}
	cout << "The highest number of consecutive pairs is: " << mostConsPair << endl;
	cout << "The word with the highest number of pairs is " << mostConsPairString <<endl;
	File.close();// To close file when done
	return 0;
}
int consecutive_pairs(const string check)
{
	int count = 0;
	for (int i = 0; i < check.size(); i++)
	{
			if (check[i] == check[i + 1])
			{
				count++;
			}
	}
	return count;
}