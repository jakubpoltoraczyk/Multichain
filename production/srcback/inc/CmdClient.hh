#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>

using namespace std; 

class CmdClient {
    public: 
        CmdClient();

        string SendRequest(string requestMsg);
        void SendRequest_noResponse(string requestMsg);


    private:
        string execute( std::string cmd );
        string execute_tee( std::string cmd );
};