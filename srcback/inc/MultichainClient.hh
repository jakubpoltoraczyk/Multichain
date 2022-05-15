#pragma once

#include "StringFinder.hh"
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
   * @brief Create a stream
   * 
   * @param chainName  name of a chain in which the stream will be created
   * @param streamName name of a stream that will be created
   */
  void createStream(string chainName, string streamName);

  /**
   * @brief Subscribe to a stream
   * 
   * @param chainName  name of a chain
   * @param streamName name of a stream to subscribe to
   */
  void subscribeToStream(string chainName, string streamName);

  /**
   * @brief Method that pushes data to a straem
   * 
   * @param chainName   name of a chain (e.g. chain1)
   * @param streamName  name of a stream (e.g. stream1)
   * @param key         name of a key (e.g. key1)
   * @param fileAddress ipfs address to be pushed to the stream
   * @param fileName    name of a file
   */
  void publishData(string chainName, string streamName, string key, string fileAddress, string fileName);

  /**
   * @brief Method that performs liststreamitems command
   *        on specified stream
   * 
   * @param chainName  name of a chain (e.g. chain1)
   * @param streamName name of a stream (e.g. stream1)
   */
  void listStreamItems(string chainName, string streamName);

  // /**
  //  * @brief Method that prints the most important information about the stream
  //  * 
  //  * @param chainName  name of a chain (e.g. chain1)
  //  * @param streamName name of a stream (e.g. stream1)
  //  */
  // void listImportantStreamItems(string chainName, string streamName);

  /**
   * @brief Method that draws ipfs address of a file from stream
   * 
   * @param chainName  name of a chain (e.g. chain1)
   * @param streamName name of a stream (e.g. stream1)
   * @param fileName   name of a file one tries to obtain address of
   * @return (string)  address of a file 
   */
  string returnFileAddress(string chainName, string streamName, string fileName);

  /**
   * @brief Lists file names existing within the chain
   * 
   * @param chainName  name of a chain
   * @param streamName name of a stream
   * @return (vector<string>) vector that contains names of the files
   */
  vector<string> listChainFiles(string chainName, string streamName);

private:
};
