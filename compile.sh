#!/bin/bash

#
#Filename       compile
#Date           2/4/21
#Author         Brianna Murray
#Course         CS 3377.0W6
#Version        1.0
#Copyright      2021, All Rights Reserved
#
#Description
#
#       Compile all files into one program AKA myprog


echo "Compiling main.cc and function.cc"
g++ -c main.cc function.cc

echo "Linking files to create executable hw1"
g++ -o myprog main.o function.o

echo "Done"
