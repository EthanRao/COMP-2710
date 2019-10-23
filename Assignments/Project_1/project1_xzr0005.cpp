/*
 * FLIE NAME: project1_xzr0005.cpp
 * AUTHOR: 
 * User ID: 
 * a program about calculate loan
 */

#include <iostream>
#include <iomanip> 
using namespace std;


int main() {
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   double loan, interRateX, interRateO, monthlySupply;
   double inter = 0;
   double principal = 0;
   double totalInter = 0;
   int month = 0; 

   cout << "Loan Amount: ";
   cin >> loan;
   cout << "Interest Rate (% per year): ";
   cin >> interRateX;
   cout << "Monthly Supply: ";
   cin >> monthlySupply;

   interRateX /= 12;
   interRateO = interRateX / 100;
   cout << endl;
   
   if (interRateO * loan >= monthlySupply) {
      cout << "The monthly supply is insufficient and the loan has been paid" <<endl;      }
   
   else {
      cout << "**********************************************************\n"
         << "\tAmortization Table\n"
         << "**********************************************************\n"
         << left << setw(8) << "Month" << left << setw(13) << "Balance" 
         << left << setw(10) << "Payment" << left << setw(7) << "Rate" 
         << left << setw(11) << "Interest" << "Principal\n"  
         << left << setw(8) << month << "$" << left << setw(12) 
         << loan << left << setw(10) << "N/A" 
         << left << setw(7) << "N/A" << left << setw(11) << "N/A" 
         << left << "N/A" << endl;
        
      while (loan > 0) {
         inter = loan*interRateO;
         principal = monthlySupply - inter;
         loan = loan - principal;
         totalInter += inter;
      
         if (loan <= 0){ 
            principal += loan;
            monthlySupply = principal + inter;
            loan = 0;
         }
       
         month ++;
         cout << left << setw(8) << month
            << "$" << left << setw(12) << loan << "$" << left << setw(9) << monthlySupply
            << left << setw(7) << interRateO*100 << "$" << left << setw(10) << inter
            << "$" << left << principal << endl;
      }
   
      cout << "**********************************************************\n"
           << "\nIt takes " << month << " months to pay off the loan.\n"
           << "Total interest paid is: $" << totalInter;
   }
   cout << endl << endl;
      
   return 0;
}
