#include "dropfileareacontroller.h"

DropFileAreaController::DropFileAreaController(QObject *parent)
    : QObject(parent) {}

void DropFileAreaController::onFileDropped(const QString &filePath) {
  emit startDroppedFileProcessing(filePath.toStdString());
}
