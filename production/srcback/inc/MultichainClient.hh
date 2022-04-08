#pragma once

#include "CmdClient.hh"

using namespace std;

class MultichainClient : public CmdClient {
public:
  MultichainClient();

  void initChain();

  void runChain();

  void publishData(string chainName, string streamName, string key, std::string fileName);

  void listStreamItems(string chainName, string streamName);

private:
};