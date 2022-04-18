#include "../inc/IpfsTests.hh"

IpfsTests::IpfsTests(){

}

bool IpfsTests::IpfsVersionTest(string resultToTest){
    string req = "ipfs version ";                               //valid
    //string req = "ipfs version 22";                           //invalid
    for (long unsigned int i = 0; i < req.length(); i++)
    {
        if (req[i] != resultToTest[i]){
            return false;
        }
    }
    return true;
}
