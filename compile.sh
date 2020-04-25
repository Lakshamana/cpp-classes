#!/bin/bash

out=`echo $1 | tr . ' ' | awk '{print $1}'`
g++ $1 -o "$out.o"