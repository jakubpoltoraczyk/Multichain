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
    
    // std::cout << "This is filePath: " << filePath << std::endl;
    // std::cout << "This is result: " << result << std::endl;  // <- result jest pusty, dlatego zwracany jest błąd out_of_range
    string start = "added ";
    string exampleVal = "QmNbcN9ADqbxS96jqBExL1JsHgLD2SUht4y1wLQhaNACss";
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
    SendRequest_noResponse("ipfs cat " + fileHash + " | tee " + fileName);
}




