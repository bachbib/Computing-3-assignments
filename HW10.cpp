/***********************************************
Author:	barah
Date:	04/25/17
Purpose:	To practice using the Algorithm library 
Sources	of	Help: tutors,	http://en.cppreference.com/w/cpp/algorithm/unique
Time	Spent:	3 hours
***********************************************/

#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
void generate_permutations(vector<string>&elements, int i, int n);
void print_permutations(vector<string>&value);
void duplicates_remove(vector<string>&elements);

int main()
{
	vector<string> inputList;
	string aLine, aString;
	// read in strings from stdin
	cout << "Enter strings, separated by a space:";
	getline(cin, aLine); //read a line from keyboard
	istringstream iss(aLine); //use
					 //parse each string	
	while (iss >> aString)
	{
		inputList.push_back(aString);
	}
	duplicates_remove(inputList);// in case there were any duplicates to remove the duplicates 
	generate_permutations(inputList,0,inputList.size()-1);

	return 0;
}

void generate_permutations(vector<string>&elements, int i, int n)
{
	if (i == n)
	{
		print_permutations(elements);
	}
	else
	{
		for (int j = i; j <= n; j++)
		{
			elements[i].swap(elements[j]);
			generate_permutations(elements, i + 1, n);
			elements[i].swap(elements[j]);
		}
	}
}

void print_permutations(vector<string>&value)
{
	static int count = 1;
	cout << count << ". ";
	count++;
	for (int j = 0; j < value.size(); j++)
	{
		cout << value[j] << ' ';
	}
	cout << endl;
}
void duplicates_remove(vector<string>&elements)
{
	sort(elements.begin(), elements.end());// to sort the vector first
	auto last = unique(elements.begin(), elements.end());// to remove the consecutive duplicate elements 
	elements.erase(last, elements.end());// to remove all the extra memory locations due to duplication 
}


/*
Computing	III	-- COMP.2010	Honor	Statement
The	 practice	 of	 good	 ethical	 behavior	 is	 essential	 for	 maintaining
good	 order	 in	 the	 classroom,	 providing	 an	 enriching	 learning
experience	 for	 students,	 and	 as	 training	 as	 a	 practicing	 computing
professional	 upon	 graduation.	 	 This	 practice	 is	 manifested	 in	 the
University’s	 Academic	 Integrity	 policy.	 Students	 are	 expected	 to
strictly	 avoid	 academic	 dishonesty	 and	 adhere	 to	 the	 Academic
Integrity	 policy	 as	 outlined	 in	 the	 course	 catalog.	 	 Violations	 will
be	dealt	with	as	outlined	therein.
All	 programming	 assignments	 in	 this	 class	 are	 to	 be	 done	 by	 the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	 in	 a	 manner	 consistent	 with	 this	 document,	 the	 course
academic	 policy	 on	 the	 course	 website	 on	 Blackboard,	 and	 the	 UMass
Lowell	academic	code.
Date: 04/25/17
Name: Barah
*/