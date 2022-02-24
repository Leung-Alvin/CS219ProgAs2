/**
    CS219 This is the driver or main file that runs the functions and implementations necessary to read the program text and write the
	appropriate output onto the linux terminal.
    @file main.cpp
    @author Alvin Leung
    @version 1.0 1/21/2022
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "operator.h"
#include "hexnum.h"

using namespace std;

/**
    Takes in a string representing an assembly command and determines what operator it is. The operator type is returned as an integer
	code.
    @param s The assembly command to be read and deciphered
    @return an int that is code for the assembly command.
*/

int isAnOperator(string s)
{
	//an "ADD" assembly command returns a code of 1. More codes for different assembly operators will be added.
	if(s == "ADD") return 1;
	return 0;
}


int main(){
	//Uses an ifstream to read the file and creates a string word to extract words from the text document
	ifstream file;
	file.open("Programming-Project-1.txt");
	string word;
	//Reads into the file
	while(file >> word){
		//When an operator keyword is found inside the text file, the ifstream reads the next two word
		if(isAnOperator(word) == 1){
			//The read words are turned into Hex Number Objects with their hex value as parameters
			file >> word;
			HexNum h1 = HexNum(word);
			file >> word;
			HexNum h2 = HexNum(word);
			//The sum of the two Hex Numbers are found by adding the integer values of the respective Hex Numbers
			HexNum sum = h1 + h2;
			//A HexNumber representing the sum is created
			//A separator is printed out to separate answers
			cout<< "----" << endl;
			//The two Hexadecimal numbers are printed out in the equation print with the Hexadecimal Number representing
			//the sum is printed last
			cout << h1.getHexName() << " + " << h2.getHexName() << " = " << sum.getHexName() << endl;
			
		}

		
		
			
	}
	return 0;

}



