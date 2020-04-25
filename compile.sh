#!/bin/bash

out=`echo $1 | tr . ' ' | awk '{print $1}'`
g++ $1 -o "$out.o"

# Use g++ -o [name].o [..].cpp -Wall 
# in order to compile with all of 
# cpp files/headers