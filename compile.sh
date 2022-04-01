#!/bin/bash

out=`echo $1 | tr . ' ' | awk '{print $1}'`
g++ $1 -o "build/$out" $2

# Use g++ -o [name].o [..].cpp -Wall 
# in order to compile with all of 
# cpp files/headers
