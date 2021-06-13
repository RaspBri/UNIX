#!/bin/bash

/*
#Filename       run
#Date           2/4/21
#Author         Brianna Murray
#Course         CS 3377.0W6
#Version        1.0
#Copyright      2021, All Rights Reserved
#
#Description
#
#       Run file will run the compiled program and append to stdout and stderr

echo "Running 'hw1' with 0 arguments"
{ ./myprog
} > stdout.log 2> stderr.log
echo "Appending stdout to stdout.log"
echo "Appending stderr to stderr.log"

echo "Running 'hw1' with 2 argumens"
{ ./myprog one two
} >> stdout.log 2>> stderr.log
echo "Appending stdout to stdout.log"
echo "Appending stderr to stderr.log"

echo "Running 'hw1' with 1 argument"
{ ./myprog two
} >> stdout.log 2>> stderr.log
echo "Appending stdout to stdout.log"
echo "Appending stderr to stderr.log"

echo "Running 'hw1' with 7 arguments"
{ ./myprog cheese steak expo marker rainbow palm tree
} >> stdout.log 2>> stderr.log
echo "Appending stdout to stdout.log"
echo "Appending stderr to stderr.log"

echo "Running 'hw1' with 12 arguments"
{ ./myprog file compile style aisle bile trial while mile kyle smile vile dial
} >> stdout.log 2>> stderr.log
echo "Appending stdout to stdout.log"
echo "Appending stderr to stderr.log"
