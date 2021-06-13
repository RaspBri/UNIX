#include "header6.h"

inline bool fileValid(string file){
  struct stat strutStat;
  return (stat(file.c_str(), &strutStat) == 0);
}

void proControl(){
  // start daemon
  if (cmdMap[DAEMON] == "true"){
    pid_t forkvalue = fork();
  }
  if (forkvalue == -1){
    cerr << "Process error forking, no child creates...\n";
    exit(0);
  } 
  else if (forkvalue == 0){
    cerr << "Daemon process will now run in background\n";
  }
  
  // create PID
  if(fileValid("cs3377dirmond.pid")){ // if PID already exists
    remove("cs3377dirmond.pid");
    exit(1);
  }
  else{ // if PID does not exist
    system("touch cs3377dirmond.pid");
    stringstream ss;

    ss << getpid();
    string pid(ss.str());

    ofstream pidFile;
    pidFile.open("cs3377dirmond.pid");
    pidFile << pid;
    pidFile.close();
  }





  return 0;
}
  
