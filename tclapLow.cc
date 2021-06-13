/*                                                                                                                     
 *Filename       tclapLow                                                                                              
 *Date           2/26/21                                                                                               
 *Author         Brianna Murray                                                                                        
 *Email          bnm180003@utdallas.edu                                                                                
 *Course         CS 3377.0U6 Spring 2021                                                                               
 *Version        1.0                                                                                                   
 *Copyright      2021, All Rights Reserved                                                                             
 *                                                                                                                     
 *Description                                                                                                          
 *                                                                                                                     
 *    Takes input file and converts it to lowercase then sends results to output file 
 */

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "header3.h"
#include <map>

using namespace std;

void tclapLow(){
	ifstream inFile;
	inFile.open("oceansog.txt");
	
	ofstream outFile;
	outFile.open("output.txt");

	string str;
	while(getline(inFile, str)){
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		outFile << str << endl;
}
	outFile.close();
	inFile.close();
}
