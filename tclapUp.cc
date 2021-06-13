/*                                                                                                                     
 *Filename       tclapUp                                                                                               
 *Date           2/26/21                                                                                               
 *Author         Brianna Murray                                                                                        
 *Email          bnm180003@utdallas.edu                                                                                
 *Course         CS 3377.0U6 Spring 2021                                                                               
 *Version        1.0                                                                                                   
 *Copyright      2021, All Rights Reserved                                                                             
 *                                                                                                                     
 *Description                                                                                                          
 *                                                                                                                     
 *   Converts input file to uppercase and sends the results to the output file. 
 */

#include <string>
#include <iostream>
#include <fstream>
#include "header3.h"
#include <algorithm>


using namespace std;

void tclapUp(){
	ifstream inFile;
	inFile.open("oceansog.txt");

	string str;

	ofstream outFile;
	outFile.open("output.txt");

	while(getline(inFile, str)){
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		outFile << str << endl;
	}


	outFile.close();
	inFile.close();
    
}
