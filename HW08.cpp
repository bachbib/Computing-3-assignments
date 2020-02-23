/***********************************************
Author:	Barah
Date: 03/26/17
Purpose: To practice using classes, as well as child classes and parent classes
Sources	of	Help: Lecture slides, Lecture code, tutoring
Time Spent:	3 hours
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
Date: 03/26/17
Name: Barah Chbib
*/

#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person();
	Person(string theName);
	Person(const Person& theObject);
	string getName() const { return name;};
	Person& operator=(const Person& rtSide);
	friend istream& operator >> (istream& inStream, Person& personObject);
	friend ostream& operator <<(ostream& outStream, const Person& pObject);
private:
	string name;
};

class Vehicle
{
public:
	Vehicle();
	Vehicle(string The_manufacture, int New_num_cyl, const Person&enter_owner);
	Vehicle(const Vehicle& theVehicle);
	Vehicle&operator=(const Vehicle& rtSide);
	string get_Manf_Name()const { return manufacture_name;};
	int get_number_of_cyl()const { return num_of_cyl; };
	Person get_owner() { return owner; };
	friend istream& operator >> (istream& inStream, Vehicle& personObject);
	friend ostream& operator <<(ostream& outStream, const Vehicle& pObject);
	
protected:
	string manufacture_name;
	int num_of_cyl;
	Person owner;
};
class Truck: public Vehicle
{
public:
	Truck();
	Truck(double capacityTons, int capacityPounds, string manufacname, int numCylinders, const Person& Nowner);
	Truck(const Truck& TruckObject);
	Truck& operator =(const Truck& theTruck);
	double get_load_tons() { return Capacity_in_tons; };
	int get_capacity_pounds() { return Capacity_in_pounds;};
	friend istream& operator >> (istream& inStream, Truck& TruckObject);
	friend ostream& operator <<(ostream& outStream, const Truck& tObject);
private:
	double Capacity_in_tons;
	int Capacity_in_pounds;
};
// Person class definitions
Person::Person() : name("none") {}
Person::Person(string theName) : name(theName) {}
Person::Person(const Person& theObject) :name(theObject.name) {}
Person& Person::operator=(const Person& rtSide)
{
	this->name = rtSide.name;
	return *this;
}
istream& operator >> (istream&inStream, Person& personObject)
{
	string temp1,temp2;
	inStream >> temp1 >> temp2;
	personObject = temp1 + " " + temp2;
	return inStream;
}
ostream& operator <<(ostream& outStream, const Person& pObject)
{
	outStream << pObject.name;
	return outStream;
}
// Vehicle class definitions
Vehicle::Vehicle() : manufacture_name("Unknown"), num_of_cyl(0), owner("No Owner") {}
Vehicle::Vehicle(string The_manufacture, int New_num_cyl, const Person&enter_owner) : manufacture_name(The_manufacture), num_of_cyl(New_num_cyl), owner(enter_owner) {}
Vehicle::Vehicle(const Vehicle& theVehicle) : manufacture_name(theVehicle.manufacture_name), num_of_cyl(theVehicle.num_of_cyl), owner(theVehicle.owner) {}
Vehicle& Vehicle:: operator=(const Vehicle& rtSide)
{
	this->owner = rtSide.owner;
	this->manufacture_name = rtSide.manufacture_name;
	this->num_of_cyl = rtSide.num_of_cyl;
	return*this;
}
istream& operator >> (istream& inStream, Vehicle& vObject)
{
	inStream >> vObject.manufacture_name;
	inStream >> vObject.num_of_cyl;
	inStream >>vObject.owner;
	return inStream;
}
ostream& operator <<(ostream& outStream, const Vehicle& vObject)
{
	outStream << vObject.manufacture_name;
	outStream << " Manufactory, ";
	outStream << vObject.num_of_cyl;
	outStream << " Cylinders, belongs to : ";
	outStream << vObject.owner ;
	outStream << endl;
	return outStream;
}

//Truck class Definitions
Truck::Truck() : Capacity_in_tons(0.0), Capacity_in_pounds(0) {}
Truck::Truck(double capacityTons, int capacityPounds, string manufacname, int numCylinders, const Person& owner) : Vehicle(manufacname, numCylinders, owner), Capacity_in_tons(capacityTons), Capacity_in_pounds(capacityPounds) {}
Truck::Truck(const Truck& TruckObject) :Vehicle(TruckObject),Capacity_in_tons(TruckObject.Capacity_in_tons), Capacity_in_pounds(TruckObject.Capacity_in_pounds) {}
Truck& Truck::operator =(const Truck& theTruck)
{
	this->Capacity_in_tons = theTruck.Capacity_in_tons;
	this->Capacity_in_pounds = theTruck.Capacity_in_pounds;
	return *this;
}

istream& operator >> (istream& inStream, Truck& TruckObject)
{
	inStream >> TruckObject.manufacture_name;
	inStream >> TruckObject.num_of_cyl;
	inStream >> TruckObject.owner;
	inStream >> TruckObject.Capacity_in_tons;
	inStream >> TruckObject.Capacity_in_pounds;
	return inStream;
}
ostream& operator <<(ostream& outStream, const Truck& tObject)
{
	outStream<< tObject.manufacture_name;
	outStream << " Manufactory, ";
	outStream << tObject.num_of_cyl;
	outStream << " Cylinders, belongs to : ";
	outStream << tObject.owner;
	outStream << ", load capacity: ";
	outStream << tObject.Capacity_in_tons;
	outStream << " towing capacity: ";
	outStream << tObject.Capacity_in_pounds;
	outStream << endl;
	return outStream;
}
// End of class defs

int main()
{
	// person class test
	Person p1;
	Person p2("MR BEAN");
	Person p3(p2);
	cout << "//////// Testing Person class ///////////////" << endl ;
	cout << "TESTING THE DEFAULT PERSON CONSTRUCTOR" << endl;
	cout << "Owner:";
	cout << p1 << endl;
	cout << "TESTING THE STRING PERSON COSTRUCTOR " << endl;
	cout << "Owner:";
	cout << p2 << endl;
	cout << "TESTING THE COPY STRING CONSTRUCTOR" << endl;
	cout << "Owner:";
	cout << p3 << endl;
	p1 = p3;
	cout << "TESTING THE = OPERATOR ON PERSON (SETTING p1 = p3)" << endl;
	cout << "Owner:";
	cout << p1<<endl;
	cout << "TESTING USER INPUT FOR OWNER" << endl;
	cout << "Please enter your first and last name: ";
	cin >> p1;
	cout << "Your name is: ";
	cout << p1 << endl<<endl;

	// vehicle class tests
	Vehicle v1;
	Vehicle v2("HONDA",4,p1);
	Vehicle v3(v2);
	cout << "//////// Testing Vehicle class ///////////////" << endl;
	cout << "TESTING THE DEFAULT VEHICLE CONSTRUCTOR" << endl << v1;
	cout << "TESTING THE INITIALIZATION VEHICLE CONSTRUCTOR " << endl << v2;
	cout << "TESTING THE COPY STRING CONSTRUCTOR" << v3;
	cout << "TESTING USER INPUT FOR VEHICLE INFORMATION" << endl;
	cout << "Please enter the manufacturer's name / number of cylinders / owner: ";
	cin >> v3;
	cout << "You entered: "<< v3;
	cout << "TESTING THE = OPERATOR ON VEHICLE (SETTING v1 = v2)" << endl;
	v1 = v3;
	cout << v1<<endl<<endl;

	// Truck class tests
	
	Truck t1;
	Truck t2(200.5,3000,"Honda",8,p1);
	Truck t3(t2);
	cout << "//////// Testing Truck class ///////////////" << endl;
	cout << "TESTING THE DEFAULT TRUCK CONSTRUCTOR" << endl << t1;
	cout << "TESTING THE INITIALIZATION TRUCK CONSTRUCTOR " << endl << t2;
	cout << "TESTING THE COPY STRING TRUCK CONSTRUCTOR" << endl << t3;
	cout << "TESTING USER INPUT FOR TRUCK INFORMATION" << endl;
	cout << "Please enter the manufacturer's name / number of cylinders / owner / load capacity (tons) / towing capacity (pounds): ";
	cin >> t3;
	cout << "You entered: "<< t3;
	cout << "TESTING THE = OPERATOR ON TRUCK (SETTING t1 = t2)" << endl;
	t1 = t3;
	cout << t1<<endl<<endl;
	// end of tests
	return 0;

}