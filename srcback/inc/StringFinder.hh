#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>


using namespace std; 

class StringFinder{
    public: 
        StringFinder();

        bool StringExistInString(string& tmp1, string& tmp2);
        string GetFirstValue(string& body, string& startString, string& endString);
        string GetFirstValue(ifstream& stream, string startString);
        string GetListOfValues(string& body, string& startString, string& endString);


    private:

};