#include "../inc/MultichainClient.hh"

MultichainClient::MultichainClient() {}

void MultichainClient::initChain() {
  SendRequest("multichain-util create chain1");
}

void MultichainClient::runChain() { SendRequest("multichaind chain1 -daemon"); }

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
