#include "../inc/MultichainClient.hh"
#include <unistd.h>

unsigned int second = 1000000;
using namespace std;

MultichainClient::MultichainClient(){

}

void MultichainClient::initChain(string chainName, string streamName) {
  cout << endl << "Creating chain..." << endl << endl;
  auto order = "multichain-util create " + chainName;     // chain creation
  auto result = SendRequest_tee(order);
  cout << endl;

  cout << "Initiating node..." << endl;
  order = "multichaind " + chainName + " -daemon";   // initiate node
  result = SendRequest_tee(order);                       // this->runChain();
  // usleep(1 * second);
  
  cout  << endl << "Creating stream..." << endl  << endl; // ! Error with creating stream while running program (maybe a delay)
  order = "multichain-cli " + chainName + " create stream " + streamName + " '{\"restrict\":\"write\"}'";   //create data stream
  result = SendRequest_tee(order);

  cout  << endl << "Subscribing to stream..."  << endl << endl;
  order = "multichain-cli " + chainName + " subscribe " + streamName;  //subscribe to the data stream
  result = SendRequest_tee(order);
}

void MultichainClient::createStream(string chainName, string streamName) {
  //cout  << endl << "Creating stream..." << endl  << endl;
  string order = "multichain-cli " + chainName + " create stream " + streamName + " '{\"restrict\":\"write\"}'";   //create data stream
  string result = SendRequest_tee(order);
}






void MultichainClient::runChain(string chainName) {
  string order = "multichaind " + chainName + " -daemon ";
  string result = SendRequest_normal(order);                  //tu musi byc normany request, bo tee blokuje program i dalej nie rusza!
}

void MultichainClient::subscribeToStream(string chainName, string streamName) {
  //cout  << endl << "Subscribing to stream..."  << endl << endl;
  string order = "multichain-cli " + chainName + " subscribe " + streamName;  //subscribe to the data stream
  string result = SendRequest_tee(order);
}

void MultichainClient::publishData(string chainName, string streamName, string key, string fileAddress, string fileName) {
  string tempJson = "'{\"json\":{\"name\":\"" + fileName + "\", \"address\":\"" + fileAddress + "\"}}'";
  string order = "multichain-cli " + chainName + " publish " + streamName + " " + key + " " + tempJson;
  SendRequest_noResponse(order);
}

void MultichainClient::listStreamItems(string chainName, string streamName) {
  string order = "multichain-cli " + chainName + " liststreamitems " + streamName + " false 100";
  string result = SendRequest_tee(order);
  // cout << result << endl;
}

string MultichainClient::returnFileAddress(string chainName, string streamName, string fileName) {
  string order = "multichain-cli " + chainName + " liststreamitems " + streamName + " false 100";
  string result = SendRequest_tee(order);

  string tmp;
  string fileAddress;
  ifstream file("result_tee.txt");
  while(true) {
    if(tmp == "\"" + fileName + "\",") {    // comma, because thats how it is codded in result.txt
      for(int i = 0; i < 3; i++) {
        file >> tmp;
        fileAddress = tmp;
      }
    }
    file >> tmp;
    if(file.eof()) break;
  }
  fileAddress.erase(0,1);
  fileAddress.erase(prev(fileAddress.end()));
  // cout << endl << endl << "to jest adres: " << fileAddress << endl;

  return fileAddress;
}

vector<string> MultichainClient::listChainFiles(string chainName, string streamName) {
  string order = "multichain-cli " + chainName + " liststreamitems " + streamName + " false 100";
  string result = SendRequest_tee(order);

  string tmp;
  ifstream file("result_tee.txt");

  vector<string> fileList;

  while(true) {
    if(tmp == "\"name\"") {
      for(int i = 0; i < 2; i++) {
        file >> tmp;
      }
      tmp.erase(0,1);               //removes quotation mark at the beginning
      tmp.erase(prev(tmp.end()));   //removes comma mark at the end
      tmp.erase(prev(tmp.end()));   //removes quotation mark at the end

      fileList.push_back(tmp);
      //cout << tmp << endl;
      // cout << "HELLO" << endl;
    }
    file >> tmp;
    if(file.eof()) break;
  }

  return fileList;
}

