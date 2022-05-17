#pragma once

#include <QObject>

class CustomMessageDialogController : public QObject {
  Q_OBJECT
public:
  using QObject::QObject;

  void showMessageDialog(const QString &titleText, const QString &contentText);

signals:
  void updateMessageDialog();

private:
  Q_PROPERTY(QString title READ getTitle NOTIFY updateMessageDialog)
  const QString &getTitle() const;
  QString title;

  Q_PROPERTY(QString content READ getContent NOTIFY updateMessageDialog)
  const QString &getContent() const;
  QString content;

  Q_PROPERTY(bool visibility MEMBER visibility NOTIFY updateMessageDialog)
  bool visibility = false;
};
