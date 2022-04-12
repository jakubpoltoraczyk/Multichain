#include "../inc/MultichainClient.hh"

MultichainClient::MultichainClient() {}

void MultichainClient::initChain(string chainName, string streamName) {
  std::cout << std::endl << "Creating chain..." << std::endl << std::endl;
  auto order = "multichain-util create " + chainName;     // chain creation
  auto result = SendRequest(order);
  std::cout << std::endl;

  std::cout << "Initiating node..." << std::endl;
  order = "multichaind " + chainName + " -daemon";   // initiate node
  result = SendRequest(order);                       // this->runChain();
  
  std::cout  << std::endl << "Creating stream..." << std::endl  << std::endl; // ! Error with creating stream while running program (maybe a delay)
  order = "multichain-cli " + chainName + " create stream " + streamName + " '{\"restrict\":\"write\"}'";   //create data stream
  result = SendRequest(order);

  std::cout  << std::endl << "Subscribing to stream..."  << std::endl << std::endl;
  order = "multichain-cli " + chainName + " subscribe " + streamName;  //subscribe to the data stream
  result = SendRequest(order);
}

void MultichainClient::runChain(string chainName) {
  auto order = "multichaind " + chainName + " -daemon";
  auto result = SendRequest(order); 
}

void MultichainClient::publishData(string chainName, string streamName,
                                   string key, std::string fileName) {
  auto tempJson = "'{\"json\":{\"address\":\"" + fileName + "\"}}'";
  auto order = "multichain-cli " + chainName + " publish " + streamName + " " +
               key + " " + tempJson;
  auto result = SendRequest(order);
}

void MultichainClient::listStreamItems(string chainName, string streamName) {
  auto order = "multichain-cli " + chainName + " liststreamitems " + streamName;
  auto result = SendRequest(order);
  std::cout << result << std::endl;
}

void MultichainClient::listImportantStreamItems(string chainName, string streamName) {
  auto order = "multichain-cli " + chainName + " liststreamitems " + streamName;
  auto result = SendRequest(order);
  // std::cout << result << std::endl;

  std::string tmp;
  std::ifstream file("result.txt");
  while(true) {
    if(tmp == "\"keys\"") {
      std::cout << "\"keys\"";
      for(int i = 0; i < 4; i++) {
        file >> tmp;
        std::cout << tmp << std::endl;
      }
    }
    if(tmp == "\"data\"") {
      std::cout << "\"data\"";
      for(int i = 0; i < 10; i++) {
        file >> tmp;
        std::cout << tmp << std::endl;
      }
    }
    file >> tmp;
    if(file.eof()) break;
  }
}