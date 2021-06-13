//Filename parseCmdLine.cc                                                                                                        
//Date 5/9/21                                                                                                             
//Version 1.0                                                                                                               
//Copyright 2021, All Rights Reserved                                                                                       
// Description                                                                                                              
// parse command line with TCLAP

#include "header6.h"

map<int, string> cmdMap;
//enum myKeys {DAEMON, CONFIG_FILE};

void parseCmdLine(int argc, char** argv){

  try{  
TCLAP::CmdLine cmd("cs3377dirmond Directory Monitor Daemon", ' ', "1.0");
  TCLAP::SwitchArg daemonSwitch("d", "daemon", "Run in daemon mode (forks to run as a daemon)", cmd, false);
  TCLAP::UnlabeledValueArg<string> configArg("config", "The name of the configuration file. Defaults to cs3377dirmond.conf", false, "cs3377dirmond.conf", "config filename", false);

  cmd.add(configArg);
  cmd.parse(argc, argv);

  // assign value to daemon
  // if daemon gets value
  if(daemonSwitch.getValue()){
    cmdMap[DAEMON] = "true";
  }
  else{ // if no value to daemon
    cmdMap[DAEMON] = "false";
  }
  // assign value to config_file
  cmdMap[CONFIG_FILE] = configArg.getValue();
  // test output
    cout << cmdMap[DAEMON] << endl;
    cout << cmdMap[CONFIG_FILE] << endl;
  }
  catch(TCLAP::ArgException &e){
    cerr << "ERROR MSG: " << e.error() << e.argId() << endl;
  }
}
