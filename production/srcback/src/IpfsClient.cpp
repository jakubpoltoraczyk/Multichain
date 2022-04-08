#include "../inc/IpfsClient.hh"

IpfsClient::IpfsClient(){

}

string IpfsClient::CheckVersion(){
    string tmp = SendRequest("ipfs --version");
    IpfsTests test;
    if(!test.IpfsVersionTest(tmp)){
        cerr << "!!! - - - IpfsClient::CheckVersion() -> version test - not valid result" << "\r\n";
    }
    return tmp;
}

string IpfsClient::AddFileToIpfs(string filePath){
    string result = SendRequest("ipfs add " + filePath);
    string start = "added ";
    string exampleVal = "QmfDrXnVCE9b7ZUKT1egBmxAvPRhdNfkuyXP4R5yvDQuF5";
    string end = " ";

    return result.substr(start.length(), exampleVal.length());
}
// commands to do

string IpfsClient::PinHashes(){
    string result = SendRequest("ipfs pin ls");
    return result;
}

string IpfsClient::GetFileFromIpfs(string fileHash){
    string result = SendRequest("ipfs cat " + fileHash + "");
    return result;
}

void IpfsClient::SafeFileFromIpfsToFile(string fileHash, string fileName){
    SendRequest_noResponse("ipfs cat " + fileHash + " >> " + fileName);
}




