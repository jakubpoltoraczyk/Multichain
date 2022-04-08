#pragma once

#include <QObject>

/** Class, which represents controller of drop file area */
class DropFileAreaController : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Create a new instance of drop file area controller
   * @param parent Pointer to parent widget
   */
  DropFileAreaController(QObject *parent = nullptr);

public slots:
  /**
   * @brief Called when parent has been just dropped
   * @param filePath Path to dropped file
   */
  void onFileDropped(const QString &filePath);

signals:
  /**
   * @brief Emitted when dropped file processing should be started
   * @param filePath Path to dropped file
   */
  void startDroppedFileProcessing(const std::string &filePath);
};
