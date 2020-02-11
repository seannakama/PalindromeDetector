/***************************************************************
*file: PalindromeDetector.cpp
*author: S. Nakama
*class: CS 2560 – C++
*assignment: Program 2
*date last modified: 9/22/2019
*
*purpose: This program reads input from a file and checks if each line contains a palindrome.
*If the file contains a palindrome, the program will output to a file whether each or not each
*line in the input file contained a palindrome. This process is done recursively.
*
****************************************************************/

#include <iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<cstdlib>
using namespace std;

bool palindrome(string str, int place, int size)
{
	while (str[place] == ' ' || str[place] == ',') {
		place++;
	}
	while (str[size] == ' ' || str[size] == ',') {
		size--;
	}
	if (tolower(str[place]) != tolower(str[size]))
		return false;

	if (place < size + 1)
		return palindrome(str, place+1, size-1);
	return true;
}

int main()
{
	fstream inf, outf;
	string inn, outn;
	int counter = 1;

	cout << "Palindrome Detector:" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Enter a file for input to test for palindromes: ";
	cin >> inn;
	inf.open(inn, ios::in);

	if (!inf)
	{
		cout << inn << " could not be opened for reading!" << endl;
		exit(1);
	}

	cout << "Enter a file for output to write the results: ";
	cin >> outn;
	cout << "Process completed! Check the output file for results." << endl;
	outf.open(outn, ios::out);

	string line;

	while (getline(inf, line)) 
	{
		if (palindrome(line, 0, line.length() - 1))
			outf << "Line " << counter << " is a palindrome" << endl;
		else
			outf << "Line " << counter << " is NOT a palindrome" << endl;
		counter++;
	}
	inf.close();
	outf.close();
}


