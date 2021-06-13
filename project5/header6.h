//Filename header6.h
//Date 5/9/21
//Author Brianna Murray
//Email bnm180003@utdallas.edu
//Version 1.0
//Copyright 2021, All Rights Reserved
// Description 
//   Have needed contents for .cc files to run


#include <map>
#include <tclap/CmdLine.h>
#include <tclap/UnlabeledValueArg.h>
#include <tclap/ValueArg.h>
#include <tclap/SwitchArg.h>

#include <rude/config.h>

#include <iostream>
#include <stdio.h>
#include <string>
#include <csignal>
#include <cstdlib>
#include <unistd.h>


using namespace std;

// maps
extern map<int, string> parameters;
enum paramKey {VERBOSE, LOGFILE, PASSWORD, NUMVERSIONS, WATCHDIR};

extern map<int, string> cmdMap;
enum myKeys {DAEMON, CONFIG_FILE};

void printHello();
void parseCmdLine(int, char**);
void parseConfigFile();
void proControl();
