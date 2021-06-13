#Filename Makefile                                                                                                        
#Date 5/9/21                                                                                                               
#Author Brianna Murray                                                                                                     
#Email bnm180003@utdallas.edu                                                                                              
#Version 1.0                                                                                                               
#Copyright 2021, All Rights Reserved                                                                                       
# Description                                                                                                              
#   Makefile to compile program     


CXX = g++
CXXFLAGS = -Wall -I /home/012/b/bn/bnm180003/include

# Library path
LDFLAGS = -L /home/012/b/bn/bnm180003/lib
LDLIBS = -lrudeconfig

OBJS = program6.o hellofunc6.o parseCmdLine.o parseConfigFile.o
PROJECTNAME = Assignment6Make
EXEC = project6

.PHONY: all clean

all: $(EXEC)

clean:
	rm -f $(OBJS) *~ $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LDFLAGS) $(LDLIBS)  

#program6.o: program6.cc header6.h
#	gcc $(CPPFLAGS) $(CXXFLAGS) -c program6.cc

#hellofunc6.o: hellofunc6.cc header6.h
#	gcc $(CPPFLAGS) $(CXXFLAGS) -c hellofunc6.cc


backup:	clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
