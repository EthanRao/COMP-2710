/* FILE NAME:	project1.cpp
 * AUTHOR: Solution
 */

#include <iostream>
using namespace std;

int main() {
	// VARIABLE INITIALIZATION
	float loan;
	float interestRate;
	float interestRateC; // Interest Rate for calculations
	float monthlyPaid;
	float interestPaid;
	float interestTotal = 0;
	float principal;
	unsigned int currentMonth = 0;
	
	// CURRENCY FORMATTING
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	// USER INPUT
	// NOTE: For valid input, the loan, interest, and monthly payment must
	// be positive. The monthly payment must also be large enough to
	// terminate the loan.
	cout << "\nLoan Amount: ";
	cin >> loan;
	while (loan <= 0) {
		cout << "Sorry, that is an invalid input.\n";
		cout << "Loan Amount: ";
		cin >> loan;
	}
	cout << "Interest Rate (% per year): ";
	cin >> interestRate;
	while  (interestRate < 0) {
		cout << "Sorry, your interest rate cannot be negative.\n";
		cout << "Interest Rate (% per year): ";
		cin >> interestRate;
	}
	// GET PROPER INTEREST RATES FOR CALCULATIONS
	interestRate /= 12;
	interestRateC = interestRate / 100;
	cout << "Monthly Payments: ";
	cin >> monthlyPaid;
	while (monthlyPaid <= loan * interestRateC || monthlyPaid <= 0) {
		cout << "Sorry, your monthly payment is insufficient.\n";
		cout << "Monthly Payments: ";
		cin >> monthlyPaid;
		
	}
	cout << endl;
	
	// AMORTIZATION TABLE
	cout << "*****************************************************************\n"
	     << "\tAmortization Table\n"
	     << "*****************************************************************\n"
	     << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

	// LOOP TO FILL TABLE
	while (loan > 0) {
		if (currentMonth == 0) {
			cout << currentMonth++ << "\t$" << loan;
		if (loan < 1000) cout << "\t"; // Formatting MAGIC
			cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
		}
		else {
		if ((loan * (1 + interestRateC) < monthlyPaid ))
			monthlyPaid = (loan * (1 + interestRateC));
		else {
			interestPaid = loan * interestRateC;
			interestTotal += interestPaid;
			principal = monthlyPaid - interestPaid;
			loan -= principal;
			cout << currentMonth++ << "\t$" << loan;
			if (loan < 1000) cout << "\t"; // Formatting MAGIC
				cout << "\t$" << monthlyPaid;
			if (monthlyPaid < 1000) cout << "\t"; //Formatting MAGIC
				cout << interestRate << "\t$"
		    		     << interestPaid << "\t";
			if (interestPaid < 1000) cout << "\t"; // More MAGIC
				cout << "$" << principal << endl;
		}
		}
	}
	cout << "****************************************************************\n";
	cout << "\nIt takes " << --currentMonth << " months to pay off "
	     << "the loan.\n"
	     << "Total interest paid is: $" << interestTotal;
	cout << endl << endl; 
	return 0;
}
