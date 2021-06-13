//Filename program6.cc                                                                                                        
//Date 5/9/21                                                                                                               
//Author Brianna Murray                                                                                                     
//Email bnm180003@utdallas.edu                                                                                              
//Version 1.0                                                                                                               
//Copyright 2021, All Rights Reserved                                                                                       
// Description                                                                                                              
//   main file that runs entire program

#include "header6.h"

int main(int argc, char** argv){
  // printHello();

  parseCmdLine(argc, argv);
  parseConfigFile();
  proControl();

  // test that this runs
  cout << "Got Here\n";
  return 0;
}
