// Jenna Laughlin
#pragma once
#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Discount
{
private:
	string firstName;
	string lastName;
	string email;
public:
	// Default Constructor
	Discount()
	{
		firstName = "";
		lastName = "";
		email = "";
	}

	// Overloaded Constructor
	Discount(string fn, string ln, string e)
	{
		// Validate entries
		if (!checkName(fn))
		{
			cout << "ERROR: First name cannot be empty.\n";
			cout << "Now closing the program.\n";
			exit(EXIT_FAILURE);
		}
		if (!checkName(ln))
		{
			cout << "ERROR: Last name cannot be empty.\n";
			cout << "Now closing the program.\n";
			exit(EXIT_FAILURE);
		}
		if (!checkEmail(e))
		{
			cout << "ERROR: Email cannot be empty.\n";
			cout << "Now closing the program.\n";
			exit(EXIT_FAILURE);
		}

		firstName = fn;
		lastName = ln;
		email = e;
	}

	// Accessor Functions
	string getFirstName() const
	{
		return firstName;
	}
	string getLastName() const
	{
		return lastName;
	}
	string getEmail() const
	{
		return email;
	}

	// Mutator Functions
	void setFirstName(string n)
	{
		while (!checkName(n))
		{
			cout << "ERROR: First name cannot be empty.\n";
			cout << "Enter again: ";
			cin >> n;
		}
		firstName = n;
	}
	void setLastName(string n)
	{
		while (!checkName(n))
		{
			cout << "ERROR: Last name cannot be empty.\n";
			cout << "Enter again: ";
			cin >> n;
		}
		lastName = n;
	}
	void setEmail(string e)
	{
		while (!checkEmail(e))
		{
			cout << "ERROR: Email cannot be empty.\n";
			cout << "Enter again: ";
			cin >> e;
		}
		email = e;
	}

	bool checkName(string name)
	{
		// Check if nothing was entered.
		if (name.size() == 0)
			return false;
		return true;
	}
	bool checkEmail(string e)
	{
		// Check if nothing was entered.
		if (e.size() == 0)
			return false;
		return true;
	}

};
#endif