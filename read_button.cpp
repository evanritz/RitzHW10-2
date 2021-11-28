// read_button.cpp
// 
// This Program takes no arguments
// This Program creates a cgi binary that intergrates with the Apache2 Web server
// On page load, the program concatenates the output HTML and displays it in the
// users web browser with the current state of the push button
//
// Written by Evan

#include <iostream>
#include <string>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "GPIO.h"

using namespace exploringBB;
using namespace cgicc;
using namespace std;

int main(int argc, char* argv[]) {

    GPIO button(46);
    
    try {

        Cgicc cgi;

        cout << HTTPHTMLHeader() << endl;
        cout << html() << endl;
        cout << head(title("RitzHW10-2 Pushbutton")) << endl;
        cout << body() << endl;
        cout << h1("CPE 422 Reading a Pushbutton as Digital Input") << endl;
        cout << h1("Reading a Pushbutton on gpio46 via a Web Browser") << endl;
        cout << "<form action=\"/cgi-bin/read_button.cgi\" method=\"POST\">" << endl;
        // Submit button just reloads the page
        cout << "<input type=\"submit\" value=\"Read Button\" name=\"Submit\">" << endl;
        cout << "</form>" << endl;
        cout << h1("Pushbutton State") << endl;

        // On every reload the page is sent with the current state
        // Pull up Resistor so Negative logic
        if (!button.getValue())
            cout << h3("Button Pressed") << endl;
        else
            cout << h3("Button Not Pressed") << endl;

        cout << body() << html();
        
    }
    catch (exception& e) {
        cout << "Error! :(";
    }
}
