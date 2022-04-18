#pragma once

#include "srcgui/dropfilearea/dropfileareacontroller.h"

#include <QObject>

#include <vector>

/** Class which represents application basic controller */
class BasicController : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Create a new instance of basic controller
   * @param parent Pointer to parent widget
   */
  BasicController(QObject *parent = nullptr);

  /**
   * @brief Provide objects to register in QML part of application
   * @return Container of objects to register
   */
  std::vector<std::pair<QString, QObject *>> getObjectsToRegister();

public slots:
  /**
   * @brief Called when dropped file process should be started
   * @param filePath Path to dropped file
   */
  void processDroppedFile(const std::string &filePath);

private:
  DropFileAreaController dropFileAreaController;
};
