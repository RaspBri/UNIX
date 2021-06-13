//Filename parseConfigFile.cc                                                                                                        
//Date 5/9/21                                                                                                               
//Author Brianna Murray                                                                                                     
//Email bnm180003@utdallas.edu                                                                                              
//Version 1.0                                                                                                               
//Copyright 2021, All Rights Reserved                                                                                       
// Description                                                                                                              
//   Parses config file to map


#include "header6.h"

map<int, string> parameters;

void parseConfigFile(){
  rude::Config config;
  config.load(cmdMap[CONFIG_FILE].c_str());
  config.setSection("Parameters");
  // send to map
  parameters[VERBOSE] = config.getStringValue("Verbose");
  parameters[LOGFILE] = config.getStringValue("LogFile");
  parameters[PASSWORD] = config.getStringValue("Password");
  parameters[NUMVERSIONS] = config.getStringValue("NumVersions");
  parameters[WATCHDIR] = config.getStringValue("WatchDir");

  // tester output
  cout << parameters[VERBOSE] << endl;
  cout << parameters[LOGFILE] << endl;
  cout << parameters[PASSWORD] << endl;
  cout << parameters[NUMVERSIONS] << endl;
  cout << parameters[WATCHDIR] << endl;

}
