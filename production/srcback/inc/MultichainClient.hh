#pragma once

#include "CmdClient.hh"

using namespace std;

class MultichainClient : public CmdClient {
public:
  MultichainClient();

  /**
   * @brief MethodMethod that checks if everything is set up correctly. 
   *        If something is missing it will be created here
   * 
   * @param chainName  name of a chain (e.g. chain1)
   * @param streamName name of a stream (e.g. stream1)
   */
  void initChain(string chainName, string streamName);

  /**
   * @brief Method that initiates a node 
   *        (will be more usefull when dealing with more than one node)
   * 
   * @param chainName name of a chain (e.g. chain1)
   */
  void runChain(string chainName);

  /**
   * @brief Method that pushes data to a straem
   * 
   * @param chainName  name of a chain (e.g. chain1)
   * @param streamName name of a stream (e.g. stream1)
   * @param key        name of a key (e.g. key1)
   * @param fileName   data to be pushed (fileadress for example)
   */
  void publishData(string chainName, string streamName, string key, std::string fileName);

  /**
   * @brief Method that performs liststreamitems command
   *        on specified stream
   * 
   * @param chainName  name of a chain (e.g. chain1)
   * @param streamName name of a stream (e.g. stream1)
   */
  void listStreamItems(string chainName, string streamName);

  /**
   * @brief Method that prints the most important information about the stream
   * 
   * @param chainName  name of a chain (e.g. chain1)
   * @param streamName name of a stream (e.g. stream1)
   */
  void listImportantStreamItems(string chainName, string streamName);
private:
};