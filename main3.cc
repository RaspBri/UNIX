/*
 *Filename       main3
 *Date           2/26/21
 *Author         Brianna Murray
 *Email          bnm180003@utdallas.edu
 *Course         CS 3377.0U6 Spring 2021
 *Version        1.0
 *Copyright      2021, All Rights Reserved
 *
 *Description
 *
 *    Main opens input file and checks if valid. Runs TCLAP flags along with storing information into the map.
 */

#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <tclap/SwitchArg.h>
#include <tclap/ValueArg.h>
#include <tclap/UnlabeledValueArg.h>
#include <tclap/CmdLine.h>
#include "header3.h"
#include <ios>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

       //Open file and check if file can be opened
  	ifstream inFile;
	inFile.open("oceansog.txt");
		if(!inFile){
		cout << "Unable to open file";
	}
	else{
		cout << "Opened file";
	}
  
		// Creating option flags for user
		TCLAP::CmdLine cmd("CS3377.0W2 Program 3", ' ', "1.0");
		TCLAP::ValueArg<std::string> outfile("o","outfile","The name of output file", false, "output.txt", "output filename");
		TCLAP::SwitchArg lowerSwitch("l","lower","Convert all text to lowercase.", cmd, false);
		TCLAP::SwitchArg upperSwitch("u","upper","Convert all text to uppercase.", cmd, false);
		TCLAP::UnlabeledValueArg<std::string> infileArg("infile", "Input file", true, "oceansog.txt", "input filename", true);
		// Connect outfile and infileArg with CmdLine
	       	cmd.add(outfile);
		cmd.add(infileArg);
		
		// Parse argc and argv
		cmd.parse(argc, argv);

		// Get values of lower/upper switch
		bool lower = lowerSwitch.getValue();
		bool upper = upperSwitch.getValue();
		
		//Check bool values and convert infile to upper or lower
		if(lower){
			cout << "Going to lower";
			tclapLow();
		}
		if(upper){
			cout << "Going to upper";
			tclapUp();
		}
		cout << "Got here";
		

		// Create map to store flags and file names
		map<int, string> optionMap;
		enum myMap{INPUT, OUTPUT, FLAGS};
		optionMap[INPUT] = infileArg.getValue();// put input into map with query
		optionMap[OUTPUT] = outfile.getValue(); 
		//if(outfile)
		//optionMap[FLAGS] = "outpile";
		if(lower)
		  optionMap[FLAGS] = "lower";
		else if(upper)
		  optionMap[FLAGS] = "upper";

		// Display Flags and file names
		cout << endl << "------------" << endl << "Input File Name: " << optionMap[INPUT] << endl;
		cout << "Output File Name: " << optionMap[OUTPUT] << endl;
		cout << "Flags Used: " << optionMap[FLAGS] << endl;
	      

	inFile.close();
	cmd.getOutput()->usage(cmd);

	return 0;
}
