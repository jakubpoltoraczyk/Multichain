#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <vector>

using namespace std; 

class CmdClient {
    public: 
        CmdClient();

        string SendRequest_normal(string requestMsg);
        string SendRequest_tee(string requestMsg);
        void SendRequest_noResponse(string requestMsg);
        void ClearConsole();

    private:
        string execute( std::string cmd );
        string execute_tee( std::string cmd );
};