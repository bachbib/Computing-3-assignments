/***********************************************
Author:	Barah
Date: 03/19/17
Purpose: To practice making a dynamic array class 
Sources	of	Help: Lecture slides, Lecture code, tutoring
Time Spent:	1 hour
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
Date: 03/20/17
Name: Barah Chbib
*/

#include<iostream>
#include<string>
using namespace std;
class DynamicStringArray
{
public:
	DynamicStringArray() { dynamicArray = nullptr; size = 0; };
	DynamicStringArray(const DynamicStringArray& dArr);
	int getSize(void) { return size; };
	void addEntry(string input);
	bool deleteEntry(string deleTing);
	string getEntry(int input);
	DynamicStringArray& operator=(const DynamicStringArray & dArr);
	~DynamicStringArray();

private:
	string *dynamicArray;
	int size;
};
int main(int argc, char* argv[])
{
	int i;
	DynamicStringArray D_ARR_INIT;
	D_ARR_INIT.addEntry("HELLO");
	D_ARR_INIT.addEntry("How");
	D_ARR_INIT.addEntry("Are");
	D_ARR_INIT.addEntry("you?");
	cout << "The initial size of the dynamic string array is: " << D_ARR_INIT.getSize()<<endl;
	for (int i = 0; i < D_ARR_INIT.getSize(); i++)
	{
		cout << D_ARR_INIT.getEntry(i) << " ";
	}
	cout << "is the initial entry"<<endl;

	DynamicStringArray D_COPY_BEFORE_CHANGE;
	D_COPY_BEFORE_CHANGE =  D_ARR_INIT;
	for (int i = 0; i < D_COPY_BEFORE_CHANGE.getSize(); i++)
	{
		cout << D_ARR_INIT.getEntry(i) << " ";
	}
	cout << "is a copy of the entry before deleting" << endl;

	DynamicStringArray D_Copy(D_ARR_INIT);
	D_Copy.deleteEntry("HELLO");
	cout << "The size of the dynamic string after deletion is: " << D_Copy.getSize() << endl;
	for (int i = 0; i < D_Copy.getSize(); i++)
	{
		cout << D_Copy.getEntry(i) << " ";
	}
		cout<<"Is the string after removing HELLO" << endl;
	return 0;
}
DynamicStringArray::DynamicStringArray(const DynamicStringArray& dArr)
{
	int i = 0;
	size = dArr.size;
	dynamicArray = new string[size];
	for (i; i < size;i++)
	{
		dynamicArray[i] = dArr.dynamicArray[i];
	}
}

void DynamicStringArray:: addEntry(string input)
{
	if (size == 0)
	{
		dynamicArray = new string[size + 1];
		dynamicArray[getSize()] = input;
		size++;
	}
	else
	{
		string *newArray = new string[size + 1];
		for (int i = 0; i<size; i++)
		{
			newArray[i] = dynamicArray[i];
		}
		newArray[size] = input;
		size++;
		dynamicArray = new string[size];
		dynamicArray = newArray;
	}
}
bool DynamicStringArray:: deleteEntry(string deleTing)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (dynamicArray[i].compare(deleTing) == 0)
			break;
	}
	if (i == size)
		return false;
	string* newString = new string[size - 1];
	int index = 0;
	for (i = 0; i < size; i++)
	{
		if (dynamicArray[i].compare(deleTing) != 0)
		{
			newString[index++] = dynamicArray[i];
		}
	}
	delete[] dynamicArray;
	dynamicArray = newString;
	size--;
	return true;
}
string DynamicStringArray:: getEntry(int input)
{
	if (input < 0 || input >= size)
		return nullptr;
	else
		return dynamicArray[input];
}
DynamicStringArray::~DynamicStringArray()
{
	delete [] dynamicArray;
}
DynamicStringArray & DynamicStringArray:: operator=(const DynamicStringArray & dArr)
{
	if (this != &dArr)
	{
		size = dArr.size;
		dynamicArray = new string[size];
		for (int i = 0; i<size; i++)
			dynamicArray[i] = dArr.dynamicArray[i];
	}
	return *this;
}

