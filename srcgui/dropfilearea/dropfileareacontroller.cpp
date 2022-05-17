#include "dropfileareacontroller.h"

void DropFileAreaController::onFileDropped(const QString &filePath) {
  emit startDroppedFileProcessing(filePath.toStdString());
}
