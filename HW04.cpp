// All set final version 

/***********************************************
Author: Barah Chbib
Date: 02/08/17
Purpose: To practice using classes to make a program that encodes and decodes five digit barcodes.
Sources of Help:
previous knolwledge in c, lecture slides, cplusplus.com, Tutoring
Time Spent: 5 days
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
Date: 02/08/17
Name: Barah Chbib
*/

#include <iostream>
#include<string>
using namespace std;
class ZipCode
{
public:
	// constructors.
	ZipCode(int codeNumber);// To input zipcode as integer
	ZipCode(string barString);// To input zipcode as barcode string
	//getters
	int getZipCode();
	string getBarCode();

private:
	//Private member variables
	int zipCode;
	//Helper function 
	int barcode_to_zipcode(string _barcode);
};// End of class
ZipCode::ZipCode(int codeNumber)// This constructor accepts the zipcode numbers and converts it into a barcode
{
	
	zipCode = codeNumber;
	
}
ZipCode::ZipCode(string barString)// This constructor accepts the barcodes and converts it into a zipcode
{
	zipCode = (barcode_to_zipcode(barString));
}
int ZipCode::getZipCode()// This member function returns the zipCode
{
	return zipCode;
}
string ZipCode::getBarCode()// This member function returns the barcode
{
	string barCode ="";
	int lastDigit; 
	int digitCount = 0;
	int div = zipCode;
	if (zipCode == 0)// if the digit entered is zero
	{
		barCode = "111000110001100011000110001";

	}
	else
	{
		while (div > 0)// To convert into barcode
		{
			// getting the last digit
			lastDigit = div % 10;
			//removing the last digit
			div = div / 10;
			digitCount++;
			if (lastDigit == 0)
			{
				barCode = "11000" + barCode;
			}
			else if (lastDigit == 1)
			{
				barCode = "00011" + barCode;
			}
			else if (lastDigit == 2)
			{
				barCode = "00101" + barCode;
			}
			else if (lastDigit == 3)
			{
				barCode = "00110" + barCode;
			}
			else if (lastDigit == 4)
			{
				barCode = "01001" + barCode;
			}
			else if (lastDigit == 5)
			{
				barCode = "01010" + barCode;
			}
			else  if (lastDigit == 6)
			{
				barCode = "01100" + barCode;
			}
			else  if (lastDigit == 7)
			{
				barCode = "10001" + barCode;
			}
			else  if (lastDigit == 8)
			{
				barCode = "10010" + barCode;
			}
			else  if (lastDigit == 9)
			{
				barCode = "10100" + barCode;
			}
			else
				cout << "wrong input\n";

		}
		if (digitCount < 5)// To count and check how many digits are in the number if they are less than 5 than we add 0's to the left
		{
			for (digitCount; digitCount <5; digitCount++)
				barCode = "11000" + barCode;
		}
		if (barCode.size() == 25)// To check if the first and the last 1's are added to make a 27 digit barcode
			barCode = "1" + barCode + "1";
	}
	return barCode;

}
int ZipCode:: barcode_to_zipcode(string _barcode)// To conver to zipcode from barcode
{ 
	int zip[5];
	int num = 0, counter, sum = 0, i = 0;
	string Arr[5];
	const int VArr[5] = { 7, 4, 2, 1, 0 };
	const int Value[5] = { 10000,1000,100,10,1 };// An array to push the number into the right place while adding the 5 digit zipcode

	if (_barcode[0] == '0' || _barcode[26] == '0')// To check if the barcode's left or right digit is zero
	{
		cout << "Wrong start/end character in the barcode!" << endl;
	}

	// To store the barcode into an array of 5 strings 
	Arr[0] = _barcode.substr(1, 5);
	Arr[1] = _barcode.substr(6, 5);
	Arr[2] = _barcode.substr(11, 5);
	Arr[3] = _barcode.substr(16, 5);
	Arr[4] = _barcode.substr(21, 5);

	for (int i = 0; i < 5; i++) // To check each subarray's values and compare with  
	{
		for (int j = 0; j < 5; j++) // To check each number in the sub array and compare it with  the values 0,1,2,4,7
		{
			if (Arr[i].at(j) == '1')// To check if the right digit was entered "0 or 1"
			{
				num += VArr[j];
			}
			else if (Arr[i].at(j) == '0')
			{
				// Do nothing
			}
			else
			{
				cout << "Wrong barcode! A barcode can only contain '0' and '1'." << endl;
			}
		}
		if (num > 9)// To force not to include numbers greater than 9 
		{
			num = 0;
		}
		zip[i] = num;
		num = 0;
	}
	for (counter = 0; counter<5; counter++)// To convert the numbers stored in the array into one number
	{
		zip[counter] *= Value[counter];
		sum += zip[counter];
	}
	return sum;
}

int main(int argc, char* argv[])
{
	ZipCode zip(99504),
		zip2("100101010011100001100110001"),
		zip3(12345),
		zip4(67890);

	cout << zip.getZipCode() << "'s bar code is '"
		<< zip.getBarCode() << "'" << endl;
	cout << zip2.getZipCode() << "'s bar code is '"
		<< zip2.getBarCode() << "'" << endl;
	cout << zip3.getZipCode() << "'s bar code is '"
		<< zip3.getBarCode() << "'" << endl;
	cout << zip4.getZipCode() << "'s bar code is '"
		<< zip4.getBarCode() << "'" << endl;

	cout << endl;

	// Test a range of values by first constructing a zip code
	// with an integer, then retrieving the bar code and using
	// that to construct another ZipCode.
	int zip_int = 0;
	for (int i = 0; i < 25; i++)
	{
		// Make an aribrary 5-digit zip code integer, and use it
		// to construct a ZipCode
		int five_digit_zip = (zip_int * zip_int) % 100000;
		ZipCode z1(five_digit_zip);
		// Construct a second ZipCode from the first's bar code
		string z1_barcode = z1.getBarCode();
		ZipCode z2(z1_barcode);

		cout.width(3);
		cout << (i + 1) << ": ";
		cout.width(5);
		cout << z2.getZipCode() << " has code '"
			<< z1_barcode << "'";

		if ((z1_barcode == z2.getBarCode()) &&
			(z1.getZipCode() == z2.getZipCode()) &&
			(z2.getZipCode() == five_digit_zip))
		{
			cout << " [OK]" << endl;
		}
		else
		{
			cout << " [ERR]" << endl;
		}

		// Increment the test value arbitrarily
		zip_int += (233 + zip_int % 7);
	}
	cout << endl;

	//// Test some error conditions. This test assumes that
	//// ZipCode will simply set its value to a flag that indicates
	//// an error, and will not exit the program.
	int BAD_ZIP_COUNT = 2;
	string bad_zips[][2] = {
		{ "100101010011100001100110000", "bad start/end character" },
		{ "100101010011100001100110021", "bad digit" },
	};
	for (int i = 0; i < BAD_ZIP_COUNT; i++)
	{
		cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
		ZipCode test(bad_zips[i][0]);
		cout << endl;
	}

	cout << "Enter a character to quit." << endl;
	char c;
	cin >> c;

	return 0;
}