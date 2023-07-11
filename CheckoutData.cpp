// Jenna Laughlin
// This program gets user input for name, email, number of 
// products purchased, and product ID's. Then it sets a 
// customerID for each customer, calculates the subtotal for
// each productID entered, and sorts the productID. It determines
// whether they qualify for free shipping and which discount level,
// then calculates the total. This is all written to 
// CheckoutData.txt.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Discount.h"
using namespace std;

// Function Prototypes
void sortArray(double*, int);
double getSubtotal(double*, int);

int main()
{
	// Set format to 2 decimal points.
	cout << fixed << setprecision(2);

	// variables
	string firstName, lastName, email;
	int customerID = 1;
	int numProducts;
	double subtotal, shipping, discount, 
		discountTotal, total;
	char again;

	// Open a file for output
	ofstream outFile;
	outFile.open("CheckoutData.txt", ios::out);

	do
	{
		// Create customer ID
		outFile << "Customer ID: " << customerID << endl;

		// Get Customer Information
		cout << "First Name: ";
		cin >> firstName;
		outFile << "First Name: " << firstName << endl;
		cout << "\nLast Name: ";
		cin >> lastName;
		outFile << "Last Name: " << lastName << endl;
		cout << "\nEmail: ";
		cin >> email;
		outFile << "Email: " << email << endl;

		

		// Display the product ID's and prices.
		cout << "\nProduct ID's:";
		cout << "\nCandle: 201 \tCandle holder: 202 \tTray: 203 "
			<< "\tTrinket tray: 204 \tSticker: 205 \tEarrings: 206";
		cout << "\nCandle: $18.00 \tCandle holder: $30.99 \tTray: $40.00 "
			<< "\tTrinket tray: $15.99 \tSticker: $5.50 \tEarrings: $15.99";
		cout << "\n";
		cout << "\nSpend more to save more! $150 = 30% off, $100 = 20% off, $75 = 10% off, $50 = 5% off";
		cout << "\nGet free shipping if you spend $50!";
		cout << "\n";

		// Get the array size.
		cout << "\nEnter the number of products purchased: ";
		cin >> numProducts;

		// dynamically allocate an array
		double* products = new double[numProducts];

		// for loop that reads values into array
		for (int count = 0; count < numProducts; count++)
		{
			// Get product ID
			cout << "\nEnter product " << count + 1 << "'s ID: ";
			cin >> *(products + count);

			// Validate input
			while (*(products + count) < 0)
			{
				cout << "ERROR: Product ID cannot be negative.\n";
				cin >> *(products + count);
			}
		}
		
		// Sort array
		sortArray(products, numProducts);

		// Display customer ID
		cout << "\nCustomer ID: " << customerID << endl;

		// Display sorted contents of array.
		cout << "Sorted product(s) are: \n";
		outFile << "Sorted product(s) are: \n";
		for (int count = 0; count < numProducts; count++)
		{
			cout << *(products + count) << " ";
			outFile << *(products + count) << " " << endl;
		}

		// Display subtotal
		cout << fixed << setprecision(2);
		cout << "\nSubtotal: $";
		cout << getSubtotal(products, numProducts);
		outFile << "Subtotal: $";
		outFile << getSubtotal(products, numProducts);

		// Define subtotal
		subtotal = getSubtotal(products, numProducts);

		// Calculate shipping
		// If subtotal is more than $50 it's free
		if (subtotal >= 50)
			shipping = 0.0;
		else shipping = 5.99;

		// Calculate discount, Spend more than $150 for 30%,
		// $100 for 20%, $75 for 10%, and $50 for 5%
		if (subtotal >= 150)
			discount = 0.3;
		else if (subtotal >= 100)
			discount = 0.2;
		else if (subtotal >= 75)
			discount = 0.1;
		else if (subtotal >= 50)
			discount = 0.05;
		else
			discount = 0.0;

		// Calculate total
		discountTotal = discount * subtotal;
		total = (subtotal - discountTotal) + shipping;

		// Display total
		cout << fixed << setprecision(2);
		cout << "\nShipping: $" << shipping << endl;
		outFile << "\nShipping: $" << shipping << endl;
		cout << "Discount: $" << discountTotal << endl;
		outFile << "Discount: $" << discountTotal << endl;
		cout << "Total: $" << total << endl;
		outFile << "Total: $" << total << endl;

		// Increment the customer ID
		customerID++;

		// Determine whether the user wants to write another record.
		cout << "Do you want to enter another record (Y/N)? ";
		cin >> again;
		cin.ignore();
	} while (again == 'Y' || again == 'y');

	// Close the opened file.
	outFile.close();
	return 0;
}

// Function to sort array
void sortArray(double* ptr, int arraySize)
{
	cout << fixed << setprecision(2);
	double temp;	// To hold temperary swap.
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		// loop through all elements in array
		for (int count = 0; count < arraySize - 1; count++)
		{
			// If following element is greater than current
			// element then swap.
			if (*(ptr + count) > * (ptr + count + 1))
			{
				temp = *(ptr + count + 1);
				*(ptr + count + 1) = *(ptr + count);
				*(ptr + count) = temp;
				swapped = true;
			}
		}
	}
}

// Function to get subtotal
double getSubtotal(double* ptr, int arraySize)
{
	cout << fixed << setprecision(2);
	double productTotal = 0.0;	// To hold subtotal

	for (int count = 0; count < arraySize; count++)
	{
		// Determine and calculate each product's cost.
		if (*(ptr + count) == 201)
			productTotal += 18.00;
		else if (*(ptr + count) == 202)
			productTotal += 30.99;
		else if (*(ptr + count) == 203)
			productTotal += 40.00;
		else if (*(ptr + count) == 204)
			productTotal += 15.99;
		else if (*(ptr + count) == 205)
			productTotal += 5.50;
		else if (*(ptr + count) == 206)
			productTotal += 15.99;
		else
			productTotal += 0.00;
	}
	return (double)productTotal;
}