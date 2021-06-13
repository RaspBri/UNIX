#!/usr/bin/make -f
                                                                                                                             
#Filename    Makefile                                                                                                         
#Date        4/9/2021                                                                                                   
#Version     1.0                                                                                                              
#Copyright   2021, All Rights Reserved                                                                                        
#Description                                                                                                                  
#Make file compiles program along with creating back up file when called, can also clean files                                                                    

CC = gcc
CCFLAGS = -Werror
CPPFLAGS = 

LEX = /bin/flex
LFLAGS = 

YACC = /bin/bison
YFLAGS = -dy

PROJECTNAME = Program5

EXECFILE = program5

OBJS = parse.o scan.o main5.o

.PRECIOUS: scan.c parse.c

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) y.tab.h parse.c parse.tab.c parser scanner scan.c *~ \#*

$(EXECFILE):	$(OBJS)
	$(CC) -o $@ $(OBJS)
	ln -fs ./$@ scanner
	ln -fs ./$@ parser

backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
