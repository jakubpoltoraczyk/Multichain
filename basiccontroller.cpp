#include "basiccontroller.h"

#include <iostream>

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
  std::cout << "Dropped file path: " << filePath << std::endl;
}
