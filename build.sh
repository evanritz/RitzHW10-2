#!/bin/bash

INPUT_FILE=read_button.cpp
OUTPUT_FILE=read_button.cgi

echo "Compiling $INPUT_FILE..."
#g++ $INPUT_FILE $EXTRA_SRC -o $OUTPUT_FILE $EXTRA_ARGS -l cgicc 
g++ $INPUT_FILE GPIO.cpp -o $OUTPUT_FILE -pthread -lcgicc
if [ $? -eq 0 ]
then
    echo "Finished Compilation, Output File: $OUTPUT_FILE"
    sudo cp $OUTPUT_FILE /usr/lib/cgi-bin/
    echo "Copied $OUTPUT_FILE to /usr/lib/bin"
    sudo chmod +s /usr/lib/cgi-bin/$OUTPUT_FILE
    echo "Made $OUTPUT_FILE executable"
    config-pin -a p8.16 in+
    echo "Configured GPIO pins"
    echo "Vist http://192.168.7.2:8080/cgi-bin/$OUTPUT_FILE"
else
    echo "Compilation Failed :("
fi

