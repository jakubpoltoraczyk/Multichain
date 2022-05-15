#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>

#include "CmdClient.hh"
#include "StringFinder.hh"
#include "MultichainClient.hh"

using namespace std; 

class MultichainInitialization{
    public: 
        MultichainInitialization();

        bool IsConnected();

        bool MultichainIsWorking();
        bool StreamIsConnected();


        string chainName  = "";
        string streamName = "";
        string keyName    = "";

};