/*
 * File name: project3.cpp
 * Name:
 * Auburn UserID:
 * Compile in Xcode and search resources of array[] in stackoverflow.
 */
#include <fstream>
#include <iostream>
#include <cstdlib> //for exit()ss
#include <cassert>
using namespace std;

const int MAX_SIZE = 100;
int readfile(int inputArray[], ifstream& instream);
/*input the files*/
int sort(int inputArray1[], int inputArray1_size,
	int inputArray2[], int inputArray2_size, int outputArray[]);
/*sort the numberof two files*/
void writefile(string file, int outputArray[], int outputArray_size);
/*output the result in the file*/

int readfile(int inputArray[], ifstream& inStream) {
   if (inStream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   int i = 0;
   inStream >> inputArray[i];
   while (!inStream.eof()) {
      i++;
      inStream >> inputArray[i];
   }
   return i;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   //variables
   int va11 = 0;
   int va22 = 0;
   int va33 = 0;
   int va44 = 0;
   
   //check values
   while (va11 < inputArray1_size && va22 < inputArray2_size) {
      if (inputArray1[va11] <= inputArray2[va22]) {
         outputArray[va33] = inputArray1[va11];
         va11++;
      }
      else {
         outputArray[va33] = inputArray2[va22];
         va22++;
      }
      va33++;
   }
   if (va11 < inputArray1_size) {
      for (va44 = va11; va44 < inputArray1_size; va44++) {
         outputArray[va33] = inputArray1[va44];
         va33++;
      }
   }
   else {
      for (va44 = va22; va44 < inputArray2_size; va44++) {
         outputArray[va33] = inputArray2[va44];
         va33++;
      }
   }
   return va33;
}

void writefile(int outputArray[], int outputArray_size, string file) {
   ofstream output;
   output.open(file.c_str());
   for (int i = 0; i < outputArray_size; i++) {
      output << outputArray[i] << "\n";
   }
   output.close();
}

int main() {
   //declare the variables
   int iArray1[MAX_SIZE];
   int iArray2[MAX_SIZE];
   int iArray1_size = 0;
   int iArray2_size = 0;
   int output[MAX_SIZE];
   string filea;
   string fileb;
   string filec;

   cout << "*** Welcome to XXXXXX's sorting program ***\n";
   cout << "Enter the first input file name: ";
   cin >> filea;
   if (iArray1_size < 0) {
      exit(1);
   }
   ifstream input1;
   input1.open(filea.c_str());
   iArray1_size = readfile(iArray1, input1);
   cout << "The list of " << iArray1_size << " numbers in file ";
   cout << filea << " is: \n";
   for (int i = 0; i < iArray1_size; i++) {
      cout << iArray1[i] << "\n";
   }
   input1.close();

   cout << "\nEnter the second input file name: ";
   cin >> fileb;
   if (iArray2_size < 0) {
      exit(1);
   }
   ifstream input2;
   input2.open(fileb.c_str());
   iArray2_size = readfile(iArray2, input2);
   cout << "The list of " << iArray2_size << " numbers in file ";
   cout << fileb << " is: \n";
   for (int i = 0; i < iArray2_size; i++) {
      cout << iArray2[i] << "\n";
   }
   input2.close();

   int outputSize = sort(iArray1, iArray1_size, iArray2, iArray2_size, output);
   cout << "\nThe sorted list of " << outputSize << " numbers is: ";
   for (int i = 0; i < outputSize; i++) {
      cout << output[i] << " ";
   }
   cout << "\nEnter the output file name: ";
   cin >> filec;
   writefile(output, outputSize, filec);
   cout << "*** Please check the new file - " << filec << " ***\n";
   cout << "*** Goodbye. ***\n";
   
   input1.close();
   input2.close();
   return 0;
}
