#include "basiccontroller.h"
#include "srcback/inc/IpfsClient.hh"
#include "srcback/inc/MultichainClient.hh"

#include <iostream>

namespace {
constexpr char FILE_PREFIX[] = "file://";
}

BasicController::BasicController(QObject *parent) : QObject(parent) {
  QObject::connect(&dropFileAreaController,
                   &DropFileAreaController::startDroppedFileProcessing, this,
                   &BasicController::processDroppedFile);
}

std::vector<std::pair<QString, QObject *>>
BasicController::getObjectsToRegister() {
  return {{"dropFileAreaController", &dropFileAreaController}};
}

void BasicController::processDroppedFile(const std::string &filePath) {
  // todo: implement dropped file processing behavior
  std::string temp = "file://";
  auto fileToProcess =
      filePath.substr(temp.length(), filePath.length() - temp.length());

  std::cout << "to jest fileToProcess: " << fileToProcess << endl;

  IpfsClient ipfsClient;
  auto fileAddress = ipfsClient.AddFileToIpfs(fileToProcess);


  string ObtainedAddressFromStream;
  vector<string> fileList;
  string fileName = fileToProcess;
  string chainName = "chain1";
  string streamName = "stream1";
  string keyName = "key1";

  MultichainClient multichainClient;
  multichainClient.initChain(chainName, streamName);
  multichainClient.createStream(chainName, streamName);
  multichainClient.subscribeToStream(chainName, streamName);
  multichainClient.publishData(chainName, streamName, keyName, fileAddress, fileName);
  multichainClient.listStreamItems(chainName, streamName); 
  ObtainedAddressFromStream = multichainClient.returnFileAddress(chainName, streamName, fileName);

  std::cout << endl << "Odzyskany adres pliku: " << ObtainedAddressFromStream << endl;

  ipfsClient.SafeFileFromIpfsToFile(ObtainedAddressFromStream, "/home/node_a/Pulpit/ImportantData.txt");

  fileList = multichainClient.listChainFiles(chainName, streamName);      //fileList is a vector of file names existing in chain
                                                                          //names can repeat themselves
  cout << "Lista plikow:" << endl;
  for (const string& i : fileList) {
    cout << i << endl;
  }
}
