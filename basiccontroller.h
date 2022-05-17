#pragma once

#include "srcgui/dropfilearea/dropfileareacontroller.h"
#include "srcgui/messagedialog/custommessagedialogcontroller.h"

#include <QObject>
#include <QStringList>

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

  /** Called when list view button has been released */
  void onListViewButtonReleased();

  /**
   * @brief Called when list view file has just been selected
   * @param customText Name of selected file
   */
  void onListViewFileSelected(const QString &fileName);

signals:
  /** Emitted when list view area should be updated */
  void updateListViewArea();

private:
  Q_PROPERTY(QStringList listViewAreaFiles READ getListViewAreaFiles NOTIFY
                 updateListViewArea)
  const QStringList &getListViewAreaFiles() const;
  QStringList listViewAreaFiles; ///< Contains files listed in list view area     //gdziekolwiek tu doloze i wyemituje sygnal, to pojawi sie item w comboboxie

  DropFileAreaController dropFileAreaController;
  CustomMessageDialogController customMessageDialogController;
};
