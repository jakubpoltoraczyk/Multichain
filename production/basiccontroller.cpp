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

  IpfsClient ipfsClient;
  auto fileAddress = ipfsClient.AddFileToIpfs(fileToProcess);

  MultichainClient multichainClient;
  multichainClient.publishData("chain1", "stream1", "key1", fileAddress);
  multichainClient.listStreamItems("chain1", "stream1");
}
