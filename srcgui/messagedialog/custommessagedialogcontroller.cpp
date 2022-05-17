#include "custommessagedialogcontroller.h"

void CustomMessageDialogController::showMessageDialog(
    const QString &titleText, const QString &contentText) {
  title = titleText;
  content = contentText;
  visibility = true;
  emit updateMessageDialog();
}

const QString &CustomMessageDialogController::getTitle() const { return title; }

const QString &CustomMessageDialogController::getContent() const {
  return content;
}
