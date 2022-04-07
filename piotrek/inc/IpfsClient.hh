#pragma once

#include "CmdClient.hh"
#include "IpfsTests.hh"

using namespace std; 

class IpfsClient : public CmdClient{
    public: 
        IpfsClient();
        string CheckVersion();
        string AddFileToIpfs(string filePath);
        string PinHashes();
        string GetFileFromIpfs(string fileHash);
        void SafeFileFromIpfsToFile(string fileHash, string fileName);

    private:

};